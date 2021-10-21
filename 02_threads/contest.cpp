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
#include <stdio.h>
#include <string.h>


using namespace std;


//Klasse Car
class Car{
    public:
        string mark; // Automarke
        int velocity;  //geschwindigkeit
        int totalTime = 0;  //gesamt Zeit

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


        //hier wird die Rundenzeit berechnet
        //IN: die Sekunde
        //OUT: totale Sekundenwert
        int get_total_time(int v){
            return totalTime + v;
        }


        //Hier werden pro Runde eine zufällige Sekundenzahl und kmh-Wert ausgegeben
        //IN: Automarke, geschwindigkeit, Rundeneingabe
        //OUT: gesamte Rundenzeit
        int lada_taiga(string mark, int v, int r){
            int rounds = 1;
            random_device rd;

            while(rounds <= r){
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
        

        void operator()(string m, int velo, int &totalTime, int rounds){
            setMark(m);
            setVelocity(velo);
            totalTime = lada_taiga(getMark(), getVelocity(), rounds);
        }


        //Eine einfache Ausgabe von der Klasse Car
        void print(){
            cout << "Car: " << mark << flush;
            cout << " / Velocity: " << to_string(velocity) << flush;
            cout << endl;
        }
};



int main(int argc, char* argv[]){

    //Benutzerschnittstelle mit Kommandozeilenparameter
    if(string(argv[1]) == "-h" || string(argv[1]) == "--help" || string(argv[1]) == "LAPS"){
        cerr << "Usage: contest [-h | --help | LAPS]" << endl;
        return 0;
    } 

    int length = strlen(argv[1]);
    for(int i = 0; i < length; i++){
        if(isalpha(argv[1][i])){
            cerr << "ERROR: Could not convert: " << argv[1][i] << "\nRun with --help for more information" << endl;
            return 0;
        }
    }

    if(atoi(argv[1]) <= 0 || atoi(argv[1]) > 16){
        cerr << "ERROR: Out of range (1 <= LAP'S < 16): " << argv[1] << "\nRun with --help for more information" << endl;
        return 0;
    }    

    //Klasse car1 & car2 deklariert
    Car car1, car2;
    string mark1 = "JET-SLI-Cabrio", mark2 = "Opel Manta";
    int velo1 = 200, velo2 = 400; 
    int totalTime1, totalTime2;

    //thread t1/t2 erstellt
    thread t1(car1, mark1, velo1, ref(totalTime1), atoi(argv[1]));
    thread t2(car2, mark2, velo2, ref(totalTime2), atoi(argv[1]));

    t1.join();
    t2.join();

    //ergänzt der Sieger und Verlier ist
    //Sieger -> endet mit kürzester Zeit
    //Verlierer -> endet mit längeren Zeit
    if(totalTime1 < totalTime2){
        cout << "Sieger ist: " << mark1 << " mit " << totalTime1 << "s" << endl;
        cout << "Verlierer ist: " << mark2 << " mit " << totalTime2 << "s" << endl;
    } else {
        cout << "Sieger ist: " << mark2 << " mit " << totalTime2 << "s" << endl;
        cout << "Verlierer ist: " << mark1 << " mit " << totalTime1 << "s" << endl;
    }
     
}
