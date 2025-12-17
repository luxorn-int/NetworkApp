#include "ConnectionAcceptor.h"

using namespace boost::asio::ip;

ConnectionAcceptor::ConnectionAcceptor(boost::asio::io_context& accept_context, unsigned short accept_port)
: port_(accept_port) ,endpoint_(tcp::endpoint(tcp::v4(), port_)) ,acceptor_(accept_context, endpoint_)
{
    WaitConnectionAccept();
}

void ConnectionAcceptor::SetConfig(boost::asio::io_context accept_context, unsigned short accept_port)
{
    port_ = accept_port;
    endpoint_ = tcp::endpoint(tcp::v4(), port_);
    acceptor_ = tcp::acceptor(accept_context, endpoint_);
}

void ConnectionAcceptor::WaitConnectionAccept() {
    acceptor_.async_accept([this](boost::system::error_code ec, tcp::socket sok)
    {
        if(!ec)
        {

        }
        WaitConnectionAccept();
    });
}
