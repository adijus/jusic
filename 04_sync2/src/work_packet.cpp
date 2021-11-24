#include <iostream>
#include "work_packet.h"
#include <string>

using namespace std;


WorkPacket::WorkPacket(int v){
    this->id = v;    
}

const int WorkPacket::getId(){
    return 0;
}