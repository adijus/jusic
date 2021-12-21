#include <iostream>
#include "clock.h"
#include "timeutils.h"
#include <chrono>
#include <unistd.h>
#include <ctime>
#include <ratio>

using namespace std;

Clock::Clock(string n){
    this->name = n;
    

}

void Clock::operator()(){
    while(true){
        chrono::time_point<chrono::system_clock> curr_time = chrono::system_clock::now();
        cout << name << ": " << curr_time << flush << "\n";
        sleep(1);
    }
    
}