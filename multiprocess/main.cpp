#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <chrono>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/times.h>
#include <sys/vtimes.h>
#include <thread>
#include <sys/time.h>

#define MAX_CHAR 5000000
using namespace std;

int parseLine(char* line){
    // This assumes that a digit will be found and the line ends in " Kb".
    int i = strlen(line);
    const char* p = line;
    while (*p <'0' || *p > '9') p++;
    line[i-3] = '\0';
    i = atoi(p);
    return i;
}

int getValue(){ //Note: this value is in KB!
    FILE* file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "VmSize:", 7) == 0){
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    return result;
}

/* cpu usage */
static clock_t lastCPU, lastSysCPU, lastUserCPU;
static int numProcessors;

class time_point;

void init(){
    FILE* file;
    struct tms timeSample;
    char line[128];

    lastCPU = times(&timeSample);
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    file = fopen("/proc/cpuinfo", "r");
    numProcessors = 0;
    while(fgets(line, 128, file) != NULL){
        if (strncmp(line, "processor", 9) == 0) numProcessors++;
    }
    fclose(file);
}

double getCurrentValue(){
    struct tms timeSample;
    clock_t now;
    double percent;

    now = times(&timeSample);
    if (now <= lastCPU || timeSample.tms_stime < lastSysCPU ||
        timeSample.tms_utime < lastUserCPU){
        //Overflow detection. Just skip this value.
        percent = -1.0;
    }
    else{
        percent = (timeSample.tms_stime - lastSysCPU) +
                  (timeSample.tms_utime - lastUserCPU);
        percent /= (now - lastCPU);
        percent /= numProcessors;
        percent *= 100;
    }
    lastCPU = now;
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    return percent;
}


int* count = static_cast<int *>(mmap(NULL, sizeof(int)*2, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS , -1, 0));
int* countChar = static_cast<int *>(mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS , -1, 0));
char* arr = static_cast<char *>(mmap(NULL, sizeof(char) * MAX_CHAR , PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS , -1, 0));


int main(int argc, char **argv)
{
    count[0] = 0;
    count[1] = 0;

    ifstream inputFile;
    if(argc != 2){
        cout<<"INVALID PATH!"<<endl<<endl;
        cout<<"Usage"<<endl;
        cout<<"\t\tmain.o [/path/to/file]"<<endl;
        return -1;
    }

    inputFile.open(argv[1]);
    char c;
    for (int i = 0; i < MAX_CHAR; ++i) {
        inputFile.get(c);
        arr[i] = c;
    }
    pid_t pid = fork(),wpid;
    int status =0;
    struct timeval tp;
    init();
    gettimeofday(&tp, NULL);
    long int before = tp.tv_sec * 1000 + tp.tv_usec / 1000;

    if (pid == 0)
    {
        // child process
        for (int i =MAX_CHAR/2; i < MAX_CHAR; ++i) {
            if (isspace(arr[i])) {
                count[0]++;
                while(isspace(arr[i]))
                    i++;
            }
            countChar++;
        }
        if(isspace(arr[MAX_CHAR/2]))
            count--;
        if(isspace(arr[MAX_CHAR-1]))
            count--;
    }
    else if (pid > 0)
    {
        // parent process
        for (int i = 0; i < MAX_CHAR/2; ++i) {
            if (isspace(arr[i])) {
                count[1]++;
                while(isspace(arr[i]))
                    i++;
            }
            countChar++;
        }
        if(isspace(arr[0]))
            count--;
        if(isspace(arr[MAX_CHAR/2 - 1]))
            count--;

        while ((wpid = wait(&status)) > 0);
        gettimeofday(&tp, NULL);
        long int after = tp.tv_sec * 1000 + tp.tv_usec / 1000;

        cout << "time is \t"<<after - before << endl;
        cout << "count is \t "<<count[0]+count[1] << endl;
        cout << "memory is \t";
        cout << getValue() << " KB" << endl;
        cout << "cpu is \t";
        cout << getCurrentValue() << endl;

    }
    else
    {
        // fork failed
        printf("fork() failed!\n");
        return 1;
    }


    return 0;
}