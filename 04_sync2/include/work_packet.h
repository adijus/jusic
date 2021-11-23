#ifndef WORKPACKET_H
#define WORKPACKET_H

#pragma once

class WorkPacket{    
    public:
        int id;  
        const int getId();
        WorkPacket(int id){this->id = id;  };

};


class WorkQueue : public WorkPacket{
    private:
        int WorkPacket::id;
    public:
        void push();
        void pop();
        using WorkPacket::WorkPacket;
};


#endif