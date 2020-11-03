#include <list>
#include <iterator>
#include "Property.hpp"

class Agency{
    public:
        Agency();
        void printProperties();
        void addProperty(Property p);
        void sellProperty(int id);
    private:
        std::list<Property> available_properties;
        std::string<Properties> sold_properties;
        std::string address;
        int employees_no;
};