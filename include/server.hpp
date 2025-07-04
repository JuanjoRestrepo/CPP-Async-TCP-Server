#pragma once

#include <boost/asio.hpp>

// Alias
using boost::asio::ip::tcp;

// Retorna la hora actual como string
std::string makeDaytimeString();

// Inicializa un acceptor TCP en el puerto dado
tcp::acceptor createAcceptor(boost::asio::io_context& ioContext, unsigned short port);

// Arranca el servidor y retorna un acceptor listo
tcp::acceptor startServer(boost::asio::io_context& ioContext, unsigned short port);

// Atiende un cliente, envía la hora y cierra conexión
void handleClient(tcp::socket socket);
