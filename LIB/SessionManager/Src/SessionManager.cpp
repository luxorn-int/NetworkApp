#include <SessionManager.h>

std::shared_ptr<ISession> SessionManager::createSession()
{
//    return std::make_shared<ISession>();
    return nullptr;
}

void SessionManager::closeAll() {}