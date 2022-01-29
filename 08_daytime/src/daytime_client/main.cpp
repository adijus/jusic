#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "asio.hpp"
#include "CLI/CLI.hpp"
#include <typeinfo>

using namespace std;
using namespace asio;
using namespace asio::ip;

int main(int argc, char* argv[]){
    CLI::App app("Daytime Client");

    unsigned short port{1113};
    app.add_option("-p,--port", port, "port to connect to");

    CLI11_PARSE(app, argc, argv);

    auto console = spdlog::stderr_color_mt("console");
    console->set_level(spdlog::level::err);

    try{
        tcp::iostream tcp_connection{"localhost", "1113"};
        if(tcp_connection){
            tcp_connection << "get time" << endl;
            string data;
            getline(tcp_connection, data);
            spdlog::info(data);
            tcp_connection.close();
        } else {
            cerr << "Could not Connect to the Server!" << endl;
        }
    } catch (asio::system_error& e){
        console->error(e.what());
    }
    
}