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


int main(){
    cout << "waiting for 3 seconds" << endl;
    pid_t pid;
    pid = fork();
    //char s1, s2;
    //if(errno == ENOSYS){
    //    cout << "log(-l) failed: " << errno << endl;
    //} else {
    //    s1 = charout();
    //    s2 = charout();
    //}
    for(int j = 0; j < 6; j++){
        if(pid == 0){
            cout << "A" << flush;

        } else if (pid > 0) {
            cout << "B" << flush;
        }
        chrono::milliseconds sleeptime(500);
        this_thread::sleep_for(sleeptime);
    }

    auto pid_tmp = pid;

    cout << endl << "killing subprocesses with pid " << pid_tmp << endl;
    cout << "waiting for subprocesses to be dead" << endl;

    kill(pid, SIGKILL);

    cout << "subprocess " << pid_tmp << " exited with 0" << endl;

    exit(EXIT_SUCCESS);

    return 0;
}
