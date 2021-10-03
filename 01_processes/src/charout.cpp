#include <iostream>
#include <unistd.h>
#include <string>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

using namespace std;

char charout(){
    char s;
    cin >> s;
    cout << s << endl;
    //chrono::milliseconds sleeptime(500);
    //this_thread::sleep_for(sleeptime);
    return s;
}
