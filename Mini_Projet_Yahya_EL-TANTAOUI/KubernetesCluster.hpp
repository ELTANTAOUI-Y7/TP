#ifndef KUBERNETESCLUSTER_HPP
#define KUBERNETESCLUSTER_HPP

#include "Resource.hpp"
#include "Container.hpp"
#include "Pod.hpp"
#include "Server.hpp"

#include <iostream>
#include <memory>
#include <vector>

class KubernetesCluster{
    private:
        std::vector<std::shared_ptr<Server>> nodes_;
        std::vector<std::unique_ptr<Pod>> pods_;
    
    public:
        void addNode(std::shared_ptr<Server> node);
        bool removePod(const std::string& name);
        void deployPod(std::unique_ptr<Pod> pod);
        std::string schedulePod(Pod& pod);
        Pod* getPod(const std::string& name);

        std::string getMetrics() const;
        friend std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c);

        //getters des attributs:
        std::vector<std::shared_ptr<Server>> get_nodes() const {return nodes_;};
        const std::vector<std::unique_ptr<Pod>>& get_pods() const {return pods_;};

};

#endif
