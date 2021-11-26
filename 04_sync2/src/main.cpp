#include <iostream>
#include <thread>
#include <mutex>
#include "work_packet.h"

using namespace std;

int main(int argc, char* argv[]){

    if(string(argv[1]) == ""){
        cout << "size is required" << endl;
        cout << "Run with --help for more information" << endl;
        return 0;
    } else if (string(argv[1]) == "-h"){
        cout << "Boss and worker simulation" << endl;
        cout << "Usage: loadsim [OPTIONS] size" << endl << endl;
        cout << "Positionals:" << endl;
        cout << "  size UNIT REQUIRED\tSize of the queue" << endl << endl;
        cout << "Options:" << endl;
        cout << "  -h,--help\t\tPrint help this message and exit" << endl;
        return 0;
    } else if (atoi(argv[1]) < 0){
        cout << "Could not convert: size = " << argv[1] << endl;
        cout << "Run with --help for more information" << endl;
        return 0;
    }
    WorkQueue q2(2);
    thread t1{[&]{WorkQueue q1(1);}};
    thread t2{[&]{WorkQueue q2(2);}};


    t1.join();
    t2.join();

}