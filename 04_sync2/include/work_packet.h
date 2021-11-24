#ifndef WORKPACKET_H
#define WORKPACKET_H

#pragma once
#include <queue>


using namespace std;

class WorkPacket{    
    public:
        int id;  
        const int getId();
        WorkPacket(int id);
};


class WorkQueue : public WorkPacket{
    private:
        queue <int> q;
    public:
        void push(const int value);
        void pop();
        WorkQueue(int v): WorkPacket::WorkPacket(v){
            int i = 0;
            while(true){
                push(i);
                i++;
            }
        };
};



#endif