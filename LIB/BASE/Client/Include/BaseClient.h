#pragma once

#include <INetworkApp.hpp>
#include <boost/asio.hpp>
#include <string>

class BaseClient : public INetworkApp
{
public:
    BaseClient();

    BaseClient(unsigned short port, std::string ipv4);

    ~BaseClient() override;

    void run() override;

    void close() override;

    bool connect_to(std::string ipv4, unsigned short port);

protected:
    boost::asio::io_context context_;

    boost::asio::ip::tcp::socket tcp_socket_;

    boost::asio::ip::udp::socket udp_socket_;

    unsigned short port_;

    std::string ipv4_;
};