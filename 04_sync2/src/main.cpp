#include <iostream>
#include <thread>
#include <mutex>
#include "work_packet.h"

using namespace std;

int main(){

    mutex m;
    WorkQueue q2(2);
    thread t1{[&]{WorkQueue q1(1);}};
    thread t2{[&]{WorkQueue q2(2);}};


    t1.join();
    t2.join();

}