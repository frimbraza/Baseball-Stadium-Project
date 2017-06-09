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
    std::string getPrice()
    {
        std::string stringPrice = std::to_string(price);
//        std::string finalString;

//        for(int i = 0; i < (int)stringPrice.size();++i)
//        {
//            if(stringPrice[i] == '.')
//            {
//                finalString = stringPrice.substr(0,i+3);
//                break;
//            }
//        }

        return stringPrice;
    }

private:
    std::string name;
    double price;
};

#endif // SOUVENIR

