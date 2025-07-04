#include<iostream>
#include<ctime>
#include<string>
#include <boost/asio.hpp>

std::string makeDaytimeString() {
    std:: time_t now = std:: time(nullptr);
    return std::ctime(&now);
}

int main() {
    std::string currentTime; 
    currentTime = makeDaytimeString();

    std::cout << "Server placeholder ✓" << std::endl;
    std::cout << "Current time: " << currentTime;
    return 0;
}