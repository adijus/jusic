#include <iostream>
#include <string>
#include <thread>
#include <cstdlib>
#include <unistd.h>
#include <chrono>
#include <functional>
#include <random>
#include <ostream>
#include <sstream>
#include <iomanip>
#include <future>
#include <signal.h>
#include <utility>

using namespace std;

class Car{
    public:
        string mark;
        int velocity;
        int totalTime = 0;

        void setMark(string m){
            this->mark = m;
        }

        string getMark(){
            return mark;
        }

        void setVelocity(int v){
            this->velocity = v;
        }

        int getVelocity(){
            return velocity;
        }

        void setTotalTime(int tt){
            totalTime = tt;
        }  

        int get_total_time(int v){
            return totalTime + v;
        }

        int lada_taiga(string mark, int v){
            int rounds = 1;
            random_device rd;

            while(rounds <= 10){
                mt19937 gen{rd()};
                uniform_real_distribution<> dis{1, 10};
                uniform_real_distribution<> kmh{50, 130};
                
                ostringstream buf;
                int randomValue = dis(gen);
                buf << to_string(rounds) << " / " << mark << " " << 
                    setprecision(3) << randomValue << "s" << " " << 
                    setprecision(3) << kmh(gen) << "km/h" << flush;
                string str = buf.str();
                cout << str << endl;
                buf.str("");

                totalTime = get_total_time(randomValue);
                this_thread::sleep_for(0.125s);
                rounds++;
            }
            return totalTime;
        }
        
        void operator()(string m, int velo, int &totalTime){
            setMark(m);
            setVelocity(velo);
            totalTime = lada_taiga(getMark(), getVelocity());
        }

        void print(){
            cout << "Car: " << mark << flush;
            cout << " / Velocity: " << to_string(velocity) << flush;
            cout << endl;
        }

};



int main(){
    
    Car car1, car2;
    string mark1 = "JET-SLI-Cabrio", mark2 = "Opel Manta";
    int velo1 = 200, velo2 = 400; 
    int totalTime1, totalTime2;

    thread t1(car1, mark1, velo1, ref(totalTime1));
    thread t2(car2, mark2, velo2, ref(totalTime2));

    t1.join();
    t2.join();

    if(totalTime1 < totalTime2){
        cout << "Sieger ist: " << mark1 << " mit " << totalTime1 << "s" << endl;
        cout << "Verlierer ist: " << mark2 << " mit " << totalTime2 << "s" << endl;
    } else {
        cout << "Sieger ist: " << mark2 << " mit " << totalTime2 << "s" << endl;
        cout << "Verlierer ist: " << mark1 << " mit " << totalTime1 << "s" << endl;
    }
     
}
