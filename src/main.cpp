#include <iostream>
#include <boost/asio.hpp>
#include "server.hpp"

using boost::asio::ip::tcp;

int main() {
    const unsigned short port = 1313;
    boost::asio::io_context ioContext;

    auto acceptor = startServer(ioContext, port);

    boost::asio::thread_pool pool(4);  // Pool con 4 hilos

    while (true) {
        std::cout << "🟢 Waiting for client...\n";
        tcp::socket socket(ioContext);
        acceptor.accept(socket);

        handleClient(pool, std::move(socket));
    }

    pool.join();  // Espera que todos los hilos terminen (nunca llegará aquí en este bucle infinito)
    return 0;
}
