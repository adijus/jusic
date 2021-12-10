#include <iostream>
#include "philosopher.h"

using namespace std;

Philosopher::Philosopher(int n){
    this->id = n;
    cout << "Philosopher " << n << " is thinking..." << endl;
}

void Philosopher::dining(){

}