#include <iostream>
#include <unistd.h>
#include <string>

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
        sleep(1);
    }



    return 0;
}
