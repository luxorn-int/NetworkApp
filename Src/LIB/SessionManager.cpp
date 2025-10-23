#include <SessionManager.h>

std::shared_ptr<Session> SessionManager::createSession()
{
    return std::make_shared<Session>();
}