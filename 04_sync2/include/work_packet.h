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
        void worker(int id, queue<int> queue);
        WorkQueue(int id): WorkPacket::WorkPacket(id){
            cout << "W" << id << ": Want work packet" << endl;
            int i = 0;
            while(i < 10){
                push(i);
                worker(WorkPacket::id, this->q);
                cout << "W" << id << ": Want work packet" << endl;
                i++;
            }
        };
};



#endif