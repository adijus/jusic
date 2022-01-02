#include <iostream>
#include "clock.h"
#include "timeutils.h"
#include <chrono>
#include <unistd.h>
#include <ctime>
#include <ratio>
#include <thread>

using namespace std;

Clock::Clock(string n){
    this->name = n;
}

void Clock::setTime(int &hours, int &minutes, int &seconds){
    this->curr_time = set_time(this->curr_time, hours, minutes, seconds);
    if(seconds == 59){
        if(minutes == 59){
            if(hours == 59){
                hours = 0;
            } else {
                hours++;
            }
            minutes = 0;
        } else {
            minutes++;
        }
        seconds = 0;
    } else {
        seconds++;
    }
}

std::chrono::time_point<std::chrono::system_clock> Clock::getCurrTime(){
    return this->curr_time;
}

std::tuple<int, int, int> Clock::getTime(){
    return get_time(curr_time);
}




Clock::Clock(string name_, int hours_, int minutes_, int seconds_){
    this->name = name_;
    
    while(true){
        setTime(hours_, minutes_, seconds_);
        cout << name << ": " << this->curr_time << flush << "\n";
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

TimeMaster::TimeMaster(string n){
    this->name = n;
}

TimeSlave::TimeSlave(string n) : TimeMaster(n){
    this->name = n;
    this->start_time = chrono::system_clock::now();
}

void TimeSlave::operator()(){
    cout << start_time << endl;
    cout << this->name << endl;
}