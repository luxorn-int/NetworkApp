#pragma once

#include <INetworkApp.hpp>
#include <SessionManager.h>
#include <ConnectionAcceptor.h>
#include <boost/asio.hpp>
#include <string>

/*
 * Прием подключений по одному порту
 * * Работа по UDP по другому порту
 * * Работа по TCP по другому порту
 */

namespace NetApp {

    //* performance splitting type
    enum class SLT {
        UNIFORM,
        PRIORITY
    };

    class BaseServer : public INetworkApp {
    public:
        explicit BaseServer();

        explicit BaseServer(uint16_t clientLimit,  SLT splitPerformanceType, unsigned short accepting_port);

        // add exiting codes
        void run() override;

        void close() override;

    protected:
        boost::asio::io_context context_;

        unsigned int client_limit_;

        unsigned short port_;

        std::string ipv4_;

        SLT split_load_type_;

        SessionManager sessionMng_;

        ConnectionAcceptor connectionAcceptor_;
    };
}