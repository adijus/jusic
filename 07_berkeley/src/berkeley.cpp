#include <iostream>
#include <thread>
#include "clock.h"

using namespace std;

int main(){
    thread clock{Clock("testclock", 12, 59, 59)};
    clock.join();
}