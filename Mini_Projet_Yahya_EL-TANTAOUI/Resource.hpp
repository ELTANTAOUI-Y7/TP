#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <iostream>

class Resource{
    protected:
        std::string id_;
        double cpu_;
        double memory_;
        bool active_ = false;

    public:
        Resource(std::string id, double cpu, double memory);
        virtual void start() = 0;
        virtual void stop() = 0;
        virtual std::string getMetrics() const = 0;
        virtual ~Resource() = default; 

        //getters des attributs
        std::string get_id() const {return id_; };
        double get_cpu() const {return cpu_; };
        double get_memory() const {return memory_; };
        bool get_active() const {return active_; };
};



#endif