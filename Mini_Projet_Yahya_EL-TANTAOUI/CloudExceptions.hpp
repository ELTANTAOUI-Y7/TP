#ifndef CLOUDEXCEPTIONS_HPP
#define CLOUDEXCEPTIONS_HPP

#include <stdexcept>
using namespace std;

class CloudException: public runtime_error{
    public:
        CloudException(const string message)
           : runtime_error(message){};

        virtual ~CloudException() = default;

};

class AllocationException: public CloudException{
    public:
      AllocationException() : 
            CloudException("Allocation Exception: Can't allocate resource"){};
     ~AllocationException() = default;

      virtual const char* what() const noexcept{
        return "Allocation Exception: Can't allocate resource";
      }

};

class FileException: public CloudException{
    public:
      FileException() : 
        CloudException("File Exception: Can't access file"){};
        
      ~FileException() = default;

      virtual const char* what() const noexcept{
        return "File Exception: Can't access file";
      }
};

#endif
