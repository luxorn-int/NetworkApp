#pragma once

class NetworkApp
{
public:
    enum class State
    {
        RUNNING
    };

    virtual ~NetworkApp() = default;

    virtual void run() = 0;

    virtual void close() = 0;

    NetworkApp(const NetworkApp&) = delete;

    NetworkApp& operator=(const NetworkApp&) = delete;

    NetworkApp(NetworkApp&&) = default;
    NetworkApp& operator=(NetworkApp&&) = default;

protected:
    NetworkApp() = default;
    
};

