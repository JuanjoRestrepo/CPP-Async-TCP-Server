#include <iostream>
#include <ctime>
#include <string>
#include <boost/asio.hpp>

// Esta línea debe ir aquí para habilitar el alias `tcp`
using boost::asio::ip::tcp;

// Función pura: retorna la hora actual como string legible
std::string makeDaytimeString() {
    std::time_t now = std::time(nullptr);
    return std::ctime(&now);
}

// Función que inicializa el aceptador TCP
tcp::acceptor createAcceptor(boost::asio::io_context& ioContext, unsigned short port) {
    tcp::endpoint endpoint(tcp::v4(), port);
    return tcp::acceptor(ioContext, endpoint);
}

// Starts the server and listens for incoming connections
void startServer(unsigned short port = 13) {
    boost::asio::io_context ioContext;
    try {
        auto acceptor = createAcceptor(ioContext, port);
        std::cout << "🟢 Listening on Port: " << port << "...\n";
    } catch (const std::exception& e) {
        std::cerr << "❌ Error: " << e.what() << std::endl;
    }
}


int main() {
    startServer(); 

    std::string currentTime; 
    currentTime = makeDaytimeString();

    std::cout << "Server placeholder ✓" << std::endl;
    std::cout << "Current time: " << currentTime;
    return 0;
}