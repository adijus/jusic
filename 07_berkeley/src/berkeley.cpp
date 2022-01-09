#include <iostream>
#include <thread>
#include "clock.h"
#include "pipe.h"

using namespace std;

int main(){
    TimeSlave s1("s1");
    s1.set_channel1(new Channel("ch1"));

    TimeMaster tm1("tm1");
    tm1.set_channel1(s1.get_channel());
    TimeMaster tm2("tm2");
    tm2.set_channel1(s1.get_channel());
    TimeMaster tm3("tm3");
    tm3.set_channel1(s1.get_channel());


    thread slave1{TimeSlave("slave1")};
    thread slave2{TimeSlave("slave2")};
    slave1.join();
    slave2.join();
}