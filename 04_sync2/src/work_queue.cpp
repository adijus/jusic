#include <iostream>
#include <thread>
#include <queue>
#include <random>
#include <unistd.h> 
#include "work_packet.h"

using namespace std;



void WorkQueue::push(const int value){
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> sec{0.00, 1.00};
    double randomSec = sec(gen);
    this_thread::sleep_for(0.5s);
    cout << "B: Submitted work packet " << value << " (" << randomSec << ") " << flush << endl;
    q.push(value);
}


void WorkQueue::pop(){
    q.pop();
}

void WorkQueue::worker(int id, queue<int> q){
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> sec{0.00, 10.00};
    double randomSec = sec(gen);
    this_thread::sleep_for(0.5s);
    cout << "W" << id << ": Got work packet " << q.back() << " (" << randomSec << ")" << flush << endl;

}