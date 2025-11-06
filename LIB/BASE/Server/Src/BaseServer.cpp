#include <BaseServer.h>

BaseServer::BaseServer(unsigned int port, unsigned int clientLimit, std::string splitLoadType)
    : client_limit_(clientLimit)
    , split_load_type_(std::move(splitLoadType))
    , tcp_acceptor_(context_)
    , udp_acceptor_(context_)

{
    
}

BaseServer::~BaseServer()
{
    close();
}

void BaseServer::run()
{

}

void BaseServer::close()
{
    sessionMng_.closeAll();
}

// TODO Дописать Базовый сервер + базовую сессию + заставить работать хоть как-то