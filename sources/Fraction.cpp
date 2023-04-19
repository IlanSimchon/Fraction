#include "Fraction.hpp"

using namespace ariel;

    Fraction::Fraction(int a , int b){
        this->mone = a;
        this->mechane = b;
    }

Fraction Fraction::operator+(Fraction a){};
Fraction Fraction::operator-(Fraction a){};
Fraction Fraction::operator*(Fraction a){};
Fraction Fraction::operator/(Fraction a){};
bool Fraction::operator==(Fraction a){
    return  this->mone == a.mone and this->mechane == a.mechane;
};
bool Fraction::operator<=(Fraction a){};
bool Fraction::operator>=(Fraction a){};
bool Fraction::operator>(Fraction a){};
bool Fraction::operator<(Fraction a){};
Fraction Fraction::operator++(){};
Fraction Fraction::operator--(){};
Fraction Fraction::operator<<(Fraction a){};
Fraction Fraction::operator>>(Fraction a){};


};