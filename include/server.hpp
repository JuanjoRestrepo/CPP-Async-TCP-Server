#pragma once

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string makeDaytimeString();
tcp::acceptor createAcceptor(boost::asio::io_context& ioContext, unsigned short port);
tcp::acceptor startServer(boost::asio::io_context& ioContext, unsigned short port);

// Nuevo: pasa la conexión al pool
void handleClient(boost::asio::thread_pool& pool, tcp::socket socket);
