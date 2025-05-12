#include "Container.hpp"
#include <iostream>
using namespace std;

Container::Container(string id, string image, double cpu, double memory):
        Resource(id, cpu, memory), image_(image){}

void Container::start(){
    if (!active_){
        active_ = true;
        cout << *this << " started successfully" << endl;
    }
    else{
        cout << *this << " aleady started" << endl;
    }
    
}

void Container::stop(){
    if (active_){
        active_ = false;
        cout << *this << " stopped successfully" << endl;
    }
    else{
        cout << *this << " aleady stopped" << endl;
    }

}

string Container::getMetrics() const{
    return "[Container: " + id_ + ": " + to_string(cpu_) + " CPU, " +
             to_string(memory_) + " Memory, " + image_ + "]";
}

string Container::get_image() const{
    return image_;
}

ostream& operator<<(ostream& os, const Container& c){
    os << c.getMetrics();
    return os;
}