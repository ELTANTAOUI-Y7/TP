#include <iostream>
using namespace std;
#include "MetricLogger.hpp"


template<typename U>
void MetricLogger<U>::logToStream(const U& obj, std::ostream& stream, std::string& name){
    stream << name << ": " << obj.getMetrics();
}