#include <gtest/gtest.h>
#include <boost/asio.hpp>
#include <thread>
#include <chrono>
#include <BaseServer.h>
#include <BaseClient.h>

using namespace NetApp;

TEST(IntegrationTest, ClientConnectsToServer) {

    BaseServer server;

    std::thread server_thread([&]() {
        server.run();
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    try {
        BaseClient client;
        EXPECT_TRUE(client.socket_.is_open());
    } catch (const std::exception& e) {
        ADD_FAILURE() << "Connection failed: " << e.what();
    }

    server.close();  // Должен прервать server.run()

    if (server_thread.joinable()) {
        server_thread.join();
    }
}