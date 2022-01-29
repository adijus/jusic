#include <iostream>
#include "spdlog/spdlog.h"
#include "asio.hpp"
#include <typeinfo>

using namespace std;
using namespace asio::ip;

int main(int argc, char* argv[]){
    if(argc == 1){
        tcp::iostream tcp_connection{"localhost", "1113"};
        if(tcp_connection){
            string data;
            getline(tcp_connection, data);
            cout << data << endl;
            tcp_connection.close();
        } else {
            cerr << "Could not Connect to the Server!" << endl;
        }
    } else if(argc == 2) {
        cout << "yes" << endl;
        string port = argv[1];
        tcp::iostream tcp_connection{"localhost", port};
        if(tcp_connection){
            string data;
            getline(tcp_connection, data);
            cout << data << endl;
            tcp_connection.close();
        } else {
            cerr << "Could not Connect to the Server!" << endl;
        }
    }
    
    
}