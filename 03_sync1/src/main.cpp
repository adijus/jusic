#include <iostream>
#include <thread>
#include "account.h"

using namespace std;



int main(){
    Account acc1, acc2;
    int balance1 = 1, balance2 = 2;
    thread t1(acc1, balance1);
    thread t2(acc2, balance2);
    t1.join();
    t2.join();
}