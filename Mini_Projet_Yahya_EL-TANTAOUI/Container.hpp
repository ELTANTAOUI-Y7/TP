#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "Resource.hpp"

class Container:public Resource{
    private:
        std::string image_;
        
    public:
        Container(std::string id, std::string image, double cpu, double memory);
        void start() override;
        void stop() override;
        std::string getMetrics() const override;
        friend std::ostream& operator<<(std::ostream& os, const Container& c);

        //getter d'image du conteneur
        std::string get_image() const;
};


#endif