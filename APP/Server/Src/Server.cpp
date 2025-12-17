#include <chatServer.h>

int main()
{
    chatServer* cht = new chatServer();

    cht->run();

    return 0;
}