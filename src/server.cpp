#include <iostream>
#include <ctime>
#include <string>
#include <boost/asio.hpp>
#include "server.hpp"

using boost::asio::ip::tcp;

std::string makeDaytimeString() {
    std::time_t now = std::time(nullptr);
    return std::ctime(&now);
}

tcp::acceptor createAcceptor(boost::asio::io_context& ioContext, unsigned short port) {
    auto endpoint = tcp::endpoint(tcp::v4(), port);
    return tcp::acceptor(ioContext, endpoint);
}

tcp::acceptor startServer(boost::asio::io_context& ioContext, unsigned short port) {
    try {
        auto acceptor = createAcceptor(ioContext, port);
        std::cout << "🟢 Listening on port " << port << "...\n";
        return acceptor;
    } catch (const std::exception& e) {
        std::cerr << "❌ Failed to start server: " << e.what() << "\n";
        std::exit(EXIT_FAILURE);
    }
}

// Nuevo: delega la escritura a un hilo del pool
void handleClient(boost::asio::thread_pool &pool, tcp::socket socket) {
    boost::asio::post(pool, [mySocket = std::move(socket)]() mutable {
        std::string message = makeDaytimeString();
        boost::system::error_code ec;
        boost::asio::write(mySocket, boost::asio::buffer(message), ec);

        if (ec) {
            std::cerr << "❌ Error sending time: " << ec.message() << "\n";
        }
    });
}
