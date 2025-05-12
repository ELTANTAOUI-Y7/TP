#include <iostream>
#include "Resource.hpp"

using namespace std;

Resource::Resource(string id, double cpu, double memory):
    id_(id), cpu_(cpu), memory_(memory){}