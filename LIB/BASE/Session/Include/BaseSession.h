#pragma once

#include <ISession.hpp>
#include <string_view>

class BaseSession : public ISession
{
public:
    ~BaseSession() override = default;
    
    bool connect_to() override;

    void disconnect() override;

    void reconnect() override;

    void close() override;

    std::string_view get_session_info();

    BaseSession();

private:
    unsigned int session_id_;

    unsigned int interruptTimer_;

    unsigned int reconnectCount_;

    unsigned int connectionTimer_;

};