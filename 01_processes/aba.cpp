#include <iostream>
#include <unistd.h>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

int main(){
    pid_t pid;
    pid = fork();

    for(int j = 0; j < 10; j++){
        if(pid == 0){
            cout << "A";
        } else {
            cout << "B";
        }
        chrono::milliseconds sleeptime(500);
        this_thread::sleep_for(sleeptime);
    }



    return 0;
}
