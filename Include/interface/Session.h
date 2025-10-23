#pragma once

class Session
{
public:
    enum class SessionState
    {
        INTERRUPTED,
        CONNECTED,
        WAIT
    };

    virtual ~Session() = default;

    virtual bool connect() = 0;

    virtual void disconnect() = 0;

    virtual void reconnect() = 0;

    virtual void close() = 0;

    Session(const Session &) = delete;

    Session &operator=(const Session &) = delete;

    Session(Session &&) = default;
    Session &operator=(Session &&) = default;

protected:
    Session() = default;
};