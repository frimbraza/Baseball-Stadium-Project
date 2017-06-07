#ifndef SOUVENIR
#define SOUVENIR
#include <iostream>

class Souvenir
{
public:
    Souvenir():name(""),price(0){}
    Souvenir (std::string n, double p):name(n),price(p){}
    void setName(std::string n){name = n;}
    void setPrice(double p){price = p;}
    std::string getName(){return name;}
    std::string getPrice(){return to_string(price);}

private:
    std::string name;
    double price;
};



#endif // SOUVENIR

