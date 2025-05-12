#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include "Resource.hpp"


class Server:public Resource{

    private:
        double available_cpu_;
        double available_memory_;
    
    public:
        Server(std::string id, double cpu, double memory);
        bool allocate(double cpu, double memory);
        void start() override;
        void stop() override;
        std::string getMetrics() const override;
        
        friend std::ostream& operator<<(std::ostream& os, const Server& s);

        //getters des attributs:
        double get_available_cpu() const {return available_cpu_;};
        double get_available_memory() const {return available_memory_;};

};


#endif