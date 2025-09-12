#include <boost/asio.hpp>
#include <FileSending.h>
#include <iostream>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;
        tcp::socket socket(io_context);

        tcp::resolver resolver(io_context);
        std::cout << "Enter IP: ";
        std::string ipaddr;
        std::getline(std::cin, ipaddr);
        std::cout << "\n";
        boost::asio::connect(socket, resolver.resolve(ipaddr.c_str(), "12345")); // Connect to localhost on port 12345

        std::cout << "Connected to server." << std::endl;

        while (true) {
            std::string message;
            std::cout << "Enter message to send (or 'exit' to quit): ";
            std::getline(std::cin, message);

            if (message == "exit") {
                break;
            }

            if (message == "")
            {
                continue;
            }

            boost::system::error_code error;
            boost::asio::write(socket, boost::asio::buffer(message), error); // Send message

            if (error) {
                throw boost::system::system_error(error);
            }

            char reply_data[1024];
            size_t reply_length = socket.read_some(boost::asio::buffer(reply_data), error); // Read reply

            if (error == boost::asio::error::eof) {
                std::cout << "Server disconnected." << std::endl;
                break;
            } else if (error) {
                throw boost::system::system_error(error);
            }

            std::cout << "Received from server: " << std::string(reply_data, reply_length) << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception in client: " << e.what() << std::endl;
    }
    return 0;
}