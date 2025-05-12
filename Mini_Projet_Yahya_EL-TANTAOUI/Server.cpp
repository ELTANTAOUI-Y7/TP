#include "Server.hpp"
#include <iostream>
using namespace std;

Server::Server(std::string id, double cpu, double memory):
        Resource(id, cpu, memory), 
        available_cpu_(cpu),
        available_memory_(memory){};

bool Server::allocate(double cpu, double memory){

    if (cpu <= available_cpu_ && memory <= available_memory_){
        available_cpu_ -= cpu;
        available_memory_ -= memory;
        cout << memory << " Memory and " << cpu << " CPU allocated to " << *this << endl;
        return true;
    }
    cout << "Couldn't allocate " << memory << " Memory, " << cpu << " CPU to " << *this << endl;
    return false;
    
};

void Server::start() {
    if (!active_){
        active_ = true;
        cout << *this << " started successfully" << endl;
    }
    else{
        cout << *this << " aleady started" << endl;
    }
};

void Server::stop() {
    if (active_){
        active_ = false;
        cout << this << " stopped successfully" << endl;
    }
    else{
        cout << this << " aleady stopped" << endl;
    }

};

std::string Server::getMetrics() const{
    return "[Server: " + id_ + ": " 
           + to_string(cpu_) + " CPU, "
           + to_string(memory_) + " Memory, "
           + to_string(available_cpu_) + " Available CPU, "
           + to_string(available_memory_) + " Available Memory]";
};

std::ostream& operator<<(std::ostream& os, const Server& s){
    os << s.getMetrics();

    return os;
};