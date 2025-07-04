#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#include "server.hpp"

using boost::asio::ip::tcp;

int main() {
    const unsigned short port = 13;
    boost::asio::io_context ioContext;

    auto acceptor = startServer(ioContext, port);

    while (true) {
        std::cout << "🟢 Waiting for client...\n";
        tcp::socket socket(ioContext);
        acceptor.accept(socket);

        std::thread clientThread(handleClient, std::move(socket));
        clientThread.detach();
    }

    return 0;
}
