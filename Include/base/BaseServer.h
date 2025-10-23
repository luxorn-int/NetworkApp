#pragma once

#include <NetworkApp.hpp>
#include <SessionManager.h>
#include <boost/asio.hpp>
#include <string>

class BaseServer : public NetworkApp
{
public:
    BaseServer();

    // BaseServer(boost::asio::io_context);

    BaseServer(unsigned int port,unsigned int clientLimit, std::string splitLoadType);

    ~BaseServer() override;

    void run() override;

    void close() override;

protected:
    boost::asio::io_context context_;

    boost::asio::ip::tcp::acceptor tcp_acceptor_;

    boost::asio::ip::udp::socket udp_acceptor_;

    unsigned int client_limit_;

    std::string split_load_type_;

    SessionManager sessionMng_;
};