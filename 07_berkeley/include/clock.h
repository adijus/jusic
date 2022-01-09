#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <chrono>
#include <pipe.h>

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

class Channel{
    private:
        std::string name;
        Pipe<long> p1;
        Pipe<long> p2;
    public:
        Channel();
        Channel(std::string n);
        Pipe<long>& get_pipe1();
        Pipe<long>& get_pipe2();
};

class TimeSlave {
    private:
        std::string name;
        std::chrono::time_point<std::chrono::system_clock> start_time;
        Channel* channel;
    public:
        TimeSlave(std::string n);
        void operator()();
        void set_channel1(Channel* ch);
        Channel* get_channel();
};

class TimeMaster{
    private:
        std::string name;  
        std::chrono::time_point<std::chrono::system_clock> start_time;
        Channel* channel;
    public:
        TimeMaster(std::string n);
        void operator()();
        void set_channel1(Channel* ch);
        Channel* get_channel();
};



#endif