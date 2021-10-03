#include <iostream>
#include <unistd.h>
#include <string>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>


using namespace std;

void func(int signum){
    wait(NULL);
}

int main(){
    pid_t pid;
    pid = fork();

    for(int j = 0; j < 12; j++){
        if(pid == 0){
            cout << "B";
        } else {
            cout << "A";
            kill(pid, SIGCHLD);
        }
        chrono::milliseconds sleeptime(500);
        this_thread::sleep_for(sleeptime);
    }
    exit(EXIT_SUCCESS);

    cout << endl;
    return 0;
}
