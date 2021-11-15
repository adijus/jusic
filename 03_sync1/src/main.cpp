#include <iostream>
#include "CLI/include/CLI/CLI.hpp"
#include <thread>
#include <mutex>
#include <string.h>
#include "account.h"

using namespace std;



int main(int argc, char* argv[]){

    if(string(argv[1]) == "--help" || string(argv[1]) == "-h"){
        cout << "Account App" << endl;
        cout << "Usage: account [OPTIONS] balance" << endl << endl;
        cout << "Positionals: " << endl << "balance INT REQUIRED \t \t Initial balance" << endl << endl;
        cout << "Options:" << endl << "  -h, --help \t \t \t Print this help message  and exit" << endl;
        cout << "  -d, --deposits INT=5 \t \t Count of deposits" << endl; 
        return 0;
    }

    if(string(argv[1]) == ""){
        cout << "balance is required" << endl;
        return 0;
    }

    int length = strlen(argv[1]);
    for(int i = 0; i < length; i++){
        if(isalpha(argv[1][i])){
            cerr << "ERROR: Could not convert: " << argv[1][i] << "\nRun with --help for more information" << endl;
            return 0;
        }
    } 

    mutex m;
    Account acc1;
    thread t1{[&]{m.lock(); lock_guard<mutex> guard(m, adopt_lock); acc1.withdraw(atoi(argv[1]));}};
    t1.join();
    
    CLI::App app("Account app");
    int balance{0};
    app.add_option("balance", balance, "Initial balance")->required();

    int deposits{5};
    app.add_option("-d, --deposits", deposits, "Count of deposits");

    CLI11_PARSE(app, argc, argv);


}