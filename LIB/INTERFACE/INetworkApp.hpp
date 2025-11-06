#pragma once

class INetworkApp
{
public:
    enum class State
    {
        RUNNING
    };

    virtual ~INetworkApp() = default;

    virtual void run() = 0;

    virtual void close() = 0;

    INetworkApp(const INetworkApp&) = delete;

    INetworkApp& operator=(const INetworkApp&) = delete;

    INetworkApp(INetworkApp&&) = default;
    INetworkApp& operator=(INetworkApp&&) = default;

protected:
    INetworkApp() = default;
    
};

