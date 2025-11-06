#pragma once

#include <memory>
#include <unordered_map>
#include <ISession.hpp>

class SessionManager
{
public:
    std::shared_ptr<ISession> createSession();

    std::shared_ptr<ISession> getSession(unsigned int SessionID);

    void removeSession(unsigned int SessionID);

    void closeAll();

private:
    std::unordered_map<unsigned int, std::shared_ptr<ISession>> sessions_;
};