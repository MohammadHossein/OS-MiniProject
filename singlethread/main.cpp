#include <iostream>
#include <fstream>
#include <sys/time.h>

#define MAX_CHAR 5000000

using namespace std;

int main() {
    char arr[MAX_CHAR];
    ifstream inputFile;
    inputFile.open("/home/dragon/CLionProjects/OS-miniProject/Files/input.txt");
    char c;
    for (int i = 0; i < MAX_CHAR; ++i) {
        inputFile.get(c);
        arr[i] = c;
    }
    int count = 0, countChar = 0;
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int before = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    for (int i = 0; i < MAX_CHAR; ++i) {
        if (isspace(arr[i])) {
            count++;
        }
        countChar++;
    }
    gettimeofday(&tp, NULL);
    long int after = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cout << after - before << endl;
    cout << countChar << endl;
    ofstream outputFile("/home/dragon/CLionProjects/OS-miniProject/Files/output.txt");
    outputFile << count + 1;
    return 0;
}