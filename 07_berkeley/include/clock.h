#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <chrono>

class Clock{
    private:
        std::string name;
        std::chrono::time_point<std::chrono::system_clock> curr_time;
    public:
        Clock(std::string n);
        Clock(std::string name_, int hours_, int minutes_, int seconds_);
        void operator()();
};

#endif