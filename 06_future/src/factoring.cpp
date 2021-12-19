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

bool isNumber(string s){
    for(int i = 0; i < s.length(); i++){
        if(isdigit(s[i])){

        } else {
            return false;
        }
    }
    return true;
}

void print(vector<InfInt> vs, string s){
    cout << s << ": ";
    for(int j = 0; j < vs.size(); j++){
        cout << vs[j] << " ";
    }
    cout << endl;
}


vector<InfInt> getPrimefactor(vector<InfInt> vs, char* argv[], int argc){
    auto start = chrono::system_clock::now();
    for(int i = 0; i < argc; i++){
            bool isDigit = isNumber(argv[i]);
            if(isDigit){
                try{
                    vs = get_factors(argv[i]);
                    print(vs, argv[i]);
                }catch(const future_error& e){
                    cerr << "Error! " << e.what() << endl;
                }
            }
    }
    auto duration = chrono::duration_cast<chrono::milliseconds>
        (std::chrono::system_clock::now() - start);
    cout << "Time elapsed used for factoring: " << duration.count() << "ms" << endl;
    return vs;
}



int main(int argc, char* argv[]){
    vector<InfInt> vs;
    if(string(argv[1]) == "-h" || string(argv[1]) == "--help"){
        cout << "Factor numbers" << endl;
        cout << "Usage: factoring [OPTIONS] number..." << endl << endl;
        cout << "Positionals:" << endl;
        cout << "  number TEXT ... REQUIRED\tnumbers to factor" << endl << endl;
        cout << "Options:" << endl;
        cout << "  -h,--help\t \t \tPrint this help message and exit" << endl;
        cout << "  -a,--async\t \t \tasync" << endl;
    } else {
        auto other{shared_future<vector<InfInt>>{async(launch::async, getPrimefactor, vs, argv, argc)}};
        //future<vector<InfInt>> pf{async(getPrimefactor, vs, argv[i])};                        
    }
}