#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <pthread.h>
#include <thread>

#define MAX_CHAR 5000000
#define THREAD_NUM 5
using namespace std;
int count = 0;
int countChar = 0;
int numThread=1;
char arr[MAX_CHAR];

void countWord(){
    int start,end;
    start = (MAX_CHAR/THREAD_NUM)*(numThread-1);
    end = (MAX_CHAR/THREAD_NUM)*(numThread);
    for (int i = start; i < end; ++i) {
        if (isspace(arr[i])) {
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
    struct timeval tp;
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

    thread f1 (countWord);
    thread f2 (countWord);
    thread f3 (countWord);
    thread f4 (countWord);
    thread f5 (countWord);

    f1.join();
    f2.join();
    f3.join();
    f4.join();
    f5.join();


    gettimeofday(&tp, NULL);
    long int after = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cout << after - before << endl;
    cout << countChar << endl;
    ofstream outputFile("/home/dragon/CLionProjects/OS-miniProject/Files/output.txt");
    outputFile << count + 1;
    return 0;
}
