#include <boost/asio.hpp>
#include <iostream>
#include <thread>

using boost::asio::ip::tcp;

void handle_client(tcp::socket socket) {
    try {
        char data[1024];
        while (true) {
            boost::system::error_code error;
            size_t length = socket.read_some(boost::asio::buffer(data), error);

            if (error == boost::asio::error::eof) {
                std::cout << "Client disconnected." << std::endl;
                break; // Connection closed cleanly by peer.
            } else if (error) {
                throw boost::system::system_error(error); // Some other error.
            }

            std::cout << "Received from client: " << std::string(data, length) << std::endl;

            // Echo back the received data
            boost::asio::write(socket, boost::asio::buffer(data, length), error);
            if (error) {
                throw boost::system::system_error(error);
            }
        }
    } catch (std::exception& e) {
        std::cerr << "Exception in client handler: " << e.what() << std::endl;
    }
}

int main() {
    try {
        boost::asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345)); // Listen on port 12345

        std::cout << "Server listening on port 12345..." << std::endl;

        while (true) {
            tcp::socket socket(io_context);
            acceptor.accept(socket); // Synchronously accept new connection
            std::cout << "Client connected from: " << socket.remote_endpoint().address().to_string() << std::endl;
            std::thread(handle_client, std::move(socket)).detach(); // Handle client in a new thread
        }
    } catch (std::exception& e) {
        std::cerr << "Exception in server: " << e.what() << std::endl;
    }
    return 0;
}