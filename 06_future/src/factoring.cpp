#include <iostream>
#include <vector>
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

int main(int argc, char* argv[]){
    //InfInt myint1 = "1543215486541318664684835184100510168404641560358";
    //InfInt myint2 = 156341300544608LL;
    //
    //myint1 *= --myint2 - 3;
    //cout << myint1 << endl;
    //
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
        for(int i = 0; i < argc; i++){
            bool isDigit = isNumber(argv[i]);
            //cout << isDigit << endl;
            if(isDigit){
                vs = get_factors(argv[i]);
                cout << argv[i] << ": ";
                for(int j = 0; j < vs.size(); j++){
                    cout << vs[j] << " ";
                }
                cout << endl;
            }
        }
        
    }
    



}