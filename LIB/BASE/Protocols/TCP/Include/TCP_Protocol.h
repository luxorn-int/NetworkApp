//
// Created by Luxorn_int_developer on 20.11.2025.
//

#ifndef NETWORKAPP_TCP_PROTOCOL_H
#define NETWORKAPP_TCP_PROTOCOL_H

#include <boost/asio.hpp>

class TCP_Protocol {
private:
    boost::asio::ip::tcp::socket socket_;

public:
    explicit TCP_Protocol();

    // IP and PORT
    void get_connection_info();
};


#endif //NETWORKAPP_TCP_PROTOCOL_H
