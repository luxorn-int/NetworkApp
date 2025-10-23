#pragma once

#include <BaseSession.h>
#include <memory>
#include <unordered_map>

class SessionManager
{
public:
    std::shared_ptr<Session> createSession();

    std::shared_ptr<Session> getSession(unsigned int SessionID);

    void removeSession(unsigned int SessionID);

    void closeAll();

private:
    std::unordered_map<unsigned int, std::shared_ptr<Session>> sessions_;
};