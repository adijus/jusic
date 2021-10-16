#include <iostream>
#include <string>
#include <thread>
#include <cstdlib>
#include <unistd.h>
#include <chrono>
#include <functional>
#include <random>

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

        void lada_taiga(string mark, int v){
            int rounds = 1;
            random_device rd;

            while(true){
                mt19937 gen{rd()};
                uniform_real_distribution<> dis{1, 10};
                uniform_real_distribution<> kmh{50, 130};
                
                cout << to_string(rounds) << flush;
                cout << " / " << flush;
                cout << mark << flush;
                cout << " " << kmh(gen) << "km/h" << flush;
                cout << " " << dis(gen) << "s" << flush;
                cout << endl;
                
                this_thread::sleep_for(1s);
                rounds++;
            }
        }
        
        void operator()(string m, int velo){
            setMark(m);
            setVelocity(velo);
            cout << "insert Car " << getMark() << " in Database" << endl;
            lada_taiga(getMark(), getVelocity());
        }

        void print(){
            cout << "Car: " << mark << flush;
            cout << " / Velocity: " << to_string(velocity) << flush;
            cout << endl;
        }

};



int main(){
    //lada_taiga("JET-SLI-Cabrio", 200);
    Car car1, car2;
    car1("JET-SLI-Cabrio", 200);
    //car2("Opel", 400);
    car1.print();
    //car2.print();

}