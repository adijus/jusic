#include <iostream>
#include <thread>
#include <mutex>
#include "account.h"

using namespace std;



int main(){
    mutex m;
    Account acc1(1);
    Account acc2(2);
    thread t1{[&]{m.lock(); lock_guard<mutex> guard(m, adopt_lock); cout << acc1.withdraw(2) << endl;}};
    thread t2{[&]{m.lock(); lock_guard<mutex> guard(m, adopt_lock); cout << acc2.withdraw(4) << endl;}};
    // t1{[&]{m.lock(); lock_guard<mutex> guard(arc1, addopt_lock); cout << withdraw() << endl;}}
    t1.join();
    t2.join();
    Depositer d1, d2;
    int n1 = 2, n2 = 5;
    thread t3(d1, n1);
    thread t4(d2, n2);
    t3.join();
    t4.join();
}