#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H


#include <mutex>



class Philosopher{
    private:
        int id;
        std::mutex left_fork;
        std::mutex right_fork;        
    public:
        Philosopher(int n);
        void dining();
};

#endif