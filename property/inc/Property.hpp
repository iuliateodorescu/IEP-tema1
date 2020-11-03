#include <iostream>
#include <string>
#include <list>
#include "Feature.hpp"

class Property{
    public:
        Property(int p_id, int b_year);
        setAddress();
        setPrice();
        setArea();
        addFeature(Feature f);
        removeFeature(Feature f);
    private:
        std::list<Feature> features;
        int state;
        int id;
        double price;
        int building_year;
        double area;
        std::string address;
};

class House : public Property{
    
};

class Flat : public Property{
    public:
        setFloor();
        getFloor();
    private:
        int floor_no;
};