#pragma once

#include <BaseServer.h>

class chatServer : public BaseServer
{
public:
    explicit chatServer(NetApp::SLT split_load_type) : BaseServer()
    {

    };
};