#include <iostream>
#include <thread>
#include <queue>
#include "work_packet.h"

using namespace std;



void WorkQueue::push(const int value){
    std::this_thread::sleep_for(500ms);
    cout << "B: Submitted work packet " << value << endl;
    q.push(value);
}


void WorkQueue::pop(){
    q.pop();
}
