#include <iostream>
#include <thread>
#include "clock.h"

using namespace std;

int main(){
    thread slave1{TimeSlave("slave1")};
    thread slave2{TimeSlave("slave2")};
    slave1.join();
    slave2.join();
}