#include <iostream>
#include <future>
#include <vector>
#include <chrono>
#include <ctype.h>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-Identation"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include "InfInt.h"
#include "calc_factors.h"
#pragma GCC diagnostic pop


using namespace std;

//hier wird geprüft, ob der Wert keine Sonderzeichen, Buchstaben, etc. besitzt
bool isNumber(string s){
    for(int i = 0; i < s.length(); i++){
        if(isdigit(s[i])){

        } else {
            return false;
        }
    }
    return true;
}

//Hier wird die Liste ausgegeben
void print(vector<InfInt> vs, string s){
    cout << s << ": ";
    for(int j = 0; j < vs.size(); j++){
        cout << vs[j] << " ";
    }
    cout << endl;
}


//Bei dieser Funktion werden die Primfaktor einer langen Zahl herausgefiltert und im vectorliste gespeichert
//Währenddessen wird auch die Zeit gemessen
vector<InfInt> getPrimefactor(vector<InfInt> vs, char* argv[], int argc){
    try{
        auto start = chrono::system_clock::now();   //Anfangszeit
        for(int i = 0; i < argc; i++){
                bool isDigit = isNumber(argv[i]);   //schaut nach, ob der Wert nur aus Zahlen besteht
                if(isDigit){
                    vs = get_factors(argv[i]);      //Primfaktoren gefiltert und in der liste gespeichert
                    print(vs, argv[i]);
                }
        }
        auto duration = chrono::duration_cast<chrono::milliseconds>
            (std::chrono::system_clock::now() - start);     //Berechnung von Anfangszeit und Endzeit
        cout << "Time elapsed used for factoring: " << duration.count() << "ms" << endl;
        return vs;
    }catch(const future_error& e){
        cerr << "Error! " << e.what() << endl;
    }
}



int main(int argc, char* argv[]){
    vector<InfInt> vs;      //vector mit dem datentyp InfInt
    //CLI11
    if(string(argv[1]) == "-h" || string(argv[1]) == "--help"){
        cout << "Factor numbers" << endl;
        cout << "Usage: factoring [OPTIONS] number..." << endl << endl;
        cout << "Positionals:" << endl;
        cout << "  number TEXT ... REQUIRED\tnumbers to factor" << endl << endl;
        cout << "Options:" << endl;
        cout << "  -h,--help\t \t \tPrint this help message and exit" << endl;
        cout << "  -a,--async\t \t \tasync" << endl;
    } else if(string(argv[1]) == "--async") {
        auto other{shared_future<vector<InfInt>>{async(launch::async, getPrimefactor, vs, argv, argc)}};                      
    }
    //CLI11
}