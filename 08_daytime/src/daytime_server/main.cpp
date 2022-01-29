#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "asio.hpp"
#include <typeinfo>
#include <ctime>
#include "timeutils.h"
#include "CLI/CLI.hpp"
#include <chrono>
#include <iomanip>



using namespace std;
using namespace asio;
using namespace asio::ip;


int main(int argc, char* argv[]){
    CLI::App app("Daytime Server");

    unsigned short port{1113};
    app.add_option("-p,--port", port, "port to connect to");

    CLI11_PARSE(app, argc, argv);

    auto console = spdlog::stderr_color_mt("console");
    console->set_level(spdlog::level::err);

    try{
        io_context ctx;
        tcp::endpoint ep{tcp::v4(), port};
        tcp::acceptor acceptor{ctx, ep};
        acceptor.listen();
        while(true){
            tcp::iostream strm{acceptor.accept()};

            string data;
            strm >> data;
            strm << std::chrono::system_clock::now();
            strm.close();
        }
    } catch(asio::system_error& e){
        console->error(e.what());
    }
    
}











//if(argc == 1){
//        tcp::iostream tcp_connection{"localhost", "1113"};
//        
//        if(tcp_connection){
//            while(true){
//                string data;
//                tcp_connection >> data;
//                tcp_connection << chrono::system_clock::now();
//                tcp_connection.close();
//            }
//
//        } else {
//            cerr << "Could not Connect to the Server!" << endl;
//        }
//    } else if(argc == 2) {
//        cout << "yes" << endl;
//        string port = argv[1];
//        tcp::iostream tcp_connection{"localhost", port};
//        if(tcp_connection){
//            string data;
//            getline(tcp_connection, data);
//            cout << data << endl;
//            tcp_connection.close();
//        } else {
//            cerr << "Could not Connect to the Server!" << endl;
//        }
//    }