#include <iostream>
#include <string>
#include <thread>
#include <cstdlib>
#include <unistd.h>
#include <chrono>

using namespace std;

class Car{
    public:
        string mark;
        int velocity;

        void setMark(string m){
            mark = m;
        }

        string getMark(){
            return mark;
        }

        void setVelocity(int v){
            velocity = v;
        }

        int getVelocity(){
            return velocity;
        }

        Car(string m, int velo){
            setMark(m);
            setVelocity(velo);
            cout << "insert Car " << getMark() << " in Database" << endl;

        }     
        
        void print(){
            cout << "Car: " << mark << " / Velocity: " << velocity << endl;
        }

        void operator()(){
            
        }
};


void lada_taiga(string mark, int v){
    int rounds = 1;
    while(true){
        cout << "Rounds: " << rounds << " / " << mark << " " << v << "km/h" << endl;
        this_thread::sleep_for(1s);
        rounds++;
    }
}


int main(){
    //lada_taiga("JET-SLI-Cabrio", 200);
    Car c1{"JET-SLI-Cabrio", 200};
    Car c2{"Opel", 400};
    c2.print();
    c1.print();
}