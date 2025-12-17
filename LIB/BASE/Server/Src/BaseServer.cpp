#include <BaseServer.h>
#include <iostream>

using namespace boost::asio::ip;

void NetApp::BaseServer::run() {

}

NetApp::BaseServer::BaseServer(uint16_t clientLimit, NetApp::SLT splitPerformanceType, unsigned short accepting_port)
: port_{accepting_port}
{

}

NetApp::BaseServer::BaseServer()
: port_{12345}, client_limit_{10}, ipv4_(tcp::)
{

}
