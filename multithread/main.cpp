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
#include <mutex>


#define MAX_CHAR 5000000
#define THREAD_NUM 2
using namespace std;
int count = 0;
int countChar = 0;
//int numThread=1;
char arr[MAX_CHAR];
mutex obj;
void countWord(int numThread){
    int start,end;
    start = (MAX_CHAR/THREAD_NUM)*(numThread-1);
    end = (MAX_CHAR/THREAD_NUM)*(numThread);
    for (int i = start; i < end; ++i) {
        if (isspace(arr[i])) {
            unique_lock<mutex> mylock(obj);
            count++;
            while(isspace(arr[i]))
                i++;
        }
        countChar++;
    }
    if(isspace(arr[start]))
        count--;
    if(isspace(arr[end-1]))
        count--;
}

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




int main(int argc,char *argv[]) {
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
    init();
    timeval tp;

    gettimeofday(&tp, NULL);


    long int before = tp.tv_sec * 1000 + tp.tv_usec / 1000;

//    pthread_t threadArray[THREAD_NUM];

//    for (int i = 0; i < THREAD_NUM; ++i) {
//        pthread_create(&threadArray[i],NULL,&countWord,NULL);
//        numThread++;
//    }

//    for (int i = 0; i < THREAD_NUM; ++i) {
//        pthread_join(threadArray[i],NULL);
//    }

    thread f1 (countWord,1);
    thread f2 (countWord,2);
//    numThread++;?
    f1.join();
    f2.join();


    gettimeofday(&tp, NULL);
    long int after = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cout << "time is \t"<<after - before << endl;
    cout << "count is \t "<<count << endl;
    cout << "memory is \t";
    cout << getValue() << " KB" << endl;
    cout << "cpu is \t";
    cout << getCurrentValue() << endl;
    ofstream outputFile("/home/dragon/CLionProjects/OS-miniProject/Files/output.txt");
    outputFile << count + 1;
    return 0;
}
