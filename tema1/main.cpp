#include <iostream>
#include <string.h>

using namespace std;

//you cannot copy a house
class HouseForSale{
    public:
        HouseForSale(int b_year)
        :building_year(b_year),
         address(),
         area(0),
         price(0)
        {}

        ~HouseForSale(){}

        void setAddress(std::string addr){ address = addr; }
        void setArea(double a){ area = a; }
        void setPrice(double p){ price = p; }
        int getYear(){ return building_year; }
        std::string getAddress(){ return address; }
        double getArea(){ return area; }
        double getPrice(){ return price; }
    private:
        int building_year;
        std::string address;
        double area;
        double price;
        HouseForSale(const HouseForSale&);
        HouseForSale& operator=(const HouseForSale&);
};

//you can copy a flat
class FlatForSale{
    public:
        FlatForSale(int b_year)
        :building_year(b_year),
         address(),
         area(0),
         price(0)
        {}

        FlatForSale(const FlatForSale &flat){
            building_year = flat.building_year;
            address = flat.address;
            area = flat.area;
            price = flat.price;
        }

        ~FlatForSale(){}

        void setAddress(std::string addr){ address = addr; }
        void setArea(double a){ area = a; }
        void setPrice(double p){ price = p; }
        int getYear(){ return building_year; }
        std::string getAddress(){ return address; }
        double getArea(){ return area; }
        double getPrice(){ return price; }

        FlatForSale& operator=(const FlatForSale &){
            return *this;
        }

        private:
            int building_year;
            std::string address;
            double area;
            double price;
};

int main()
{
    HouseForSale h1(2010);
    h1.setAddress("Daliei, nr5");
    h1.setArea(120);
    h1.setPrice(50000);

    FlatForSale f1(2019);
    f1.setAddress("Stuparilor, nr95A");
    f1.setArea(80);
    f1.setPrice(40000);

    //HouseForSale h2(h1);
    //HouseForSale h3 = HouseForSale(h1);
    FlatForSale f2(f1);
    FlatForSale f3 = FlatForSale(f1);

    cout<<"Flat 1:\nbuilding year\t"<<f1.getYear()<<"\naddress\t"<<f1.getAddress()<<"\narea\t"<<f1.getArea()<<"\nprice\t"<<f1.getPrice()<<"\n\n";
    cout<<"Flat 2:\nbuilding year\t"<<f2.getYear()<<"\naddress\t"<<f2.getAddress()<<"\narea\t"<<f2.getArea()<<"\nprice\t"<<f2.getPrice()<<"\n\n";
    cout<<"Flat 3:\nbuilding year\t"<<f3.getYear()<<"\naddress\t"<<f3.getAddress()<<"\narea\t"<<f3.getArea()<<"\nprice\t"<<f3.getPrice()<<"\n\n";

}