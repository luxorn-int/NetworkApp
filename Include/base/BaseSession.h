#pragma once

#include <Session.h>

class BaseSession : public Session
{
public:
    ~BaseSession() override = default;
    
    bool connect() override;

    void disconnect() override;

    void reconnect() override;

    void close() override;

    BaseSession();

private:
    unsigned int session_id_;

    // Если клиент пропал и не отвечает N секунд
    unsigned int interruptTimer_;
 
    // Сколько раз надо пытаться переподсоединиться
    unsigned int reconnectCount_;

    // Сколько ждать ответа клиента
    unsigned int connectionTimer_;

};