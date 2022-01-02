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
        std::chrono::time_point<std::chrono::system_clock> getCurrTime();
        void setTime(int &hours, int &minutes, int &seconds);
        std::tuple<int, int, int> getTime();
        void operator()();
};

class TimeMaster{
    private:
        std::string name;  
        std::chrono::time_point<std::chrono::system_clock> start_time;
    public:
        TimeMaster(std::string n);
        void operator()();
};

class TimeSlave : public TimeMaster{
    private:
        std::string name;
        std::chrono::time_point<std::chrono::system_clock> start_time;
    public:
        TimeSlave(std::string n);
        void operator()();
};



#endif