#include "Container.h"
#include <sstream>

Container::Container(std::string id, std::string image, double cpu, double memory)
    : Resource(std::move(id), cpu, memory), image_(std::move(image)) {}

void Container::start() {
    active_ = true;
}

void Container::stop() {
    active_ = false;
}

std::string Container::getMetrics() const {
    std::stringstream ss;
    ss << "[Container: " << id_ << ": " << cpu_ << " CPU, " << memory_ << " Memory, " << image_ << "]";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Container& c) {
    os << c.getMetrics();
    return os;
} 