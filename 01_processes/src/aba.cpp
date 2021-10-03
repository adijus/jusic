#include <iostream>
#include <unistd.h>
#include <string>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <cerrno>


using namespace std;

char charout();

void func(int signum){
    wait(NULL);
}

int main(){
    pid_t pid;
    pid = fork();
    char s1, s2;
    if(errno == ENOSYS){
        cout << "log(-l) failed: " << errno << endl;
    } else {
        s1 = charout();
        s2 = charout();
    }
    
    for(int j = 0; j < 6; j++){

        if(pid == 0){
            cout << s1;

        } else {
            cout << s2;
            kill(pid, SIGCHLD);
        }
        chrono::milliseconds sleeptime(500);
        this_thread::sleep_for(sleeptime);
        pid = fork();
    }
    exit(EXIT_SUCCESS);

    cout << endl;
    return 0;
}
