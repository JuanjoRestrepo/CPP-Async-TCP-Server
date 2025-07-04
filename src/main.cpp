#include <iostream>
#include <ctime>
#include <string>
#include <boost/asio.hpp>

// Enable the alias `tcp` for boost::asio::ip::tcp
using boost::asio::ip::tcp;

// Returns the current time as a string
std::string makeDaytimeString() {
    std::time_t now = std::time(nullptr);
    return std::ctime(&now);
}

// —————————————————— SERVER INITIALIZATION —————————————————— 

// Initializes a TCP acceptor to listen on the specified port
tcp::acceptor createAcceptor(boost::asio::io_context &ioContext, unsigned short port) {
    auto endpoint = tcp::endpoint(tcp::v4(), port);
    return tcp::acceptor(ioContext, endpoint);
}

// Starts the server and listens for incoming connections
tcp::acceptor startServer(boost::asio::io_context &ioContext, unsigned short port) {
    try {
        auto acceptor = createAcceptor(ioContext, port);
        std::cout << "🟢 Listening on Port: " << port << std::endl;
        return acceptor;
    } catch (const std::exception &e) {
        throw std::runtime_error("❌ Failed to start server");
        std::cerr << "-> Error: " << e.what() << std::endl;
        std::exit(EXIT_FAILURE);
    }
}


// —————————————————— CLIENTS MANAGEMENT ——————————————————

// Accepts a client, sends the current time, and closes the socket
void handleClient(tcp::socket socket) {
    std::string message = makeDaytimeString();
    boost::system::error_code ec;
    boost::asio::write(socket, boost::asio::buffer(message), ec);

    if (ec) {
        std::cerr << "❌ Error sending time: " << ec.message() << "\n";
    }
}

// getCurrentTime
void showCurrentTime() {
    std::string currentTime; 
    currentTime = makeDaytimeString();
    std::cout << "Server placeholder ✓" << std::endl;
    std::cout << "Current time: " << currentTime;
}

int main() {
    unsigned short port = 13;
    boost::asio::io_context ioContext;

    // Starts the server and listens for incoming connections
    auto acceptor = startServer(ioContext, port);

    while (true) {
        std::cout << "🟢 Waiting for client...\n";

        tcp::socket socket(ioContext);
        acceptor.accept(socket);

        std::thread clientThread(handleClient, std::move(socket));
        clientThread.detach(); // no bloqueamos el hilo principal
    }


    //showCurrentTime();
    
    return 0;
}