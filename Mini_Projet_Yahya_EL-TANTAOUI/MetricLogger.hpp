#ifndef METRICLOGGER_HPP
#define METRICLOGGER_HPP

#include <iostream>

template<typename U>
class MetricLogger{
    public:
        void logToStream(const U& obj, std::ostream& stream, std::string& name);
};

#endif