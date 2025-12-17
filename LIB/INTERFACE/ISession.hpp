#pragma once

class ISession
{
public:
    enum class STATE {CONNECT, CONNECTING, DISCONNECT, ERR};

    virtual ~ISession() = default;

    virtual bool connect_to() = 0;

    virtual void disconnect() = 0;

    virtual void reconnect() = 0;

    virtual void close() = 0;

    ISession(const ISession &) = delete;

    ISession &operator=(const ISession &) = delete;

    ISession(ISession &&) = default;
    ISession &operator=(ISession &&) = default;

protected:
    ISession() = default;
};