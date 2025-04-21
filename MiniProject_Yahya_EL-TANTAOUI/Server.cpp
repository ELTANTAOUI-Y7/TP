#include "Server.h"
#include <sstream>

Server::Server(std::string id, double cpu, double memory)
    : Resource(std::move(id), cpu, memory), available_cpu_(cpu), available_memory_(memory) {}

bool Server::allocate(double cpu, double memory) {
    if (cpu <= available_cpu_ && memory <= available_memory_) {
        available_cpu_ -= cpu;
        available_memory_ -= memory;
        return true;
    }
    return false;
}

void Server::start() {
    active_ = true;
}

void Server::stop() {
    active_ = false;
}

std::string Server::getMetrics() const {
    std::stringstream ss;
    ss << "[Server: " << id_ << ": " << cpu_ << " CPU, " << memory_ << " Memory, Available: " 
       << available_cpu_ << " CPU, " << available_memory_ << " Memory]";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Server& s) {
    os << s.getMetrics();
    return os;
} 