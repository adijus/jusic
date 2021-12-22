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


Clock::Clock(string name_, int hours_, int minutes_, int seconds_){
    this->name = name_;
    while(true){
        curr_time = set_time(curr_time, hours_, minutes_, seconds_);
        if(seconds_ == 59){
            if(minutes_ == 59){
                if(hours_ == 59){
                    hours_ = 0;
                } else {
                    hours_++;
                }
                minutes_ = 0;
            } else {
                minutes_++;
            }
            seconds_ = 0;
        } else {
            seconds_++;
        }
        cout << name << ": " << curr_time << flush << "\n";
        sleep(1);
    }
    
    
}

void Clock::operator()(){
    while(true){
        curr_time = chrono::system_clock::now();
        cout << name << ": " << curr_time << flush << "\n";
        sleep(1);
    }
    
}