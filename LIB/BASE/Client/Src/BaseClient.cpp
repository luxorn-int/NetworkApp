#include <BaseClient.h>
#include <iostream>

using namespace boost::asio::ip;

BaseClient::BaseClient() :
    socket_(io_)
{
    socket_.connect(tcp::endpoint(
            boost::asio::ip::make_address("127.0.0.1"), 8080));

    std::cout << "Connected! Type messages:" << std::endl;

    std::string message;

}

BaseClient::~BaseClient() {

}

void BaseClient::run() {

}

void BaseClient::close() {

}

bool BaseClient::connect_to(std::string ipv4, unsigned short port) {
    return false;
}

BaseClient::BaseClient(unsigned short port, std::string ipv4) {

};