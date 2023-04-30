#include "iostream"
using namespace  std;
namespace  ariel {

    class Fraction {
    public:
        int numerator;
        int denominator;

        Fraction(int a, int b);

        Fraction operator+(Fraction a);

        Fraction operator+(float a);

        friend Fraction operator+(float a, Fraction f);

        Fraction operator-(Fraction a);

        Fraction operator-(float a);

        friend Fraction operator-(float a, Fraction f);

        Fraction operator*(Fraction a);

        Fraction operator*(float);

        friend Fraction operator*(float a, Fraction f);

        Fraction operator/(Fraction a);

        Fraction operator/(float a);

        friend Fraction operator/(float a, Fraction f);

        bool operator==(Fraction a);

        bool operator==(float a);

        friend bool operator==(float a, Fraction f);

        bool operator<=(Fraction a);

        bool operator<=(float a);

        friend bool operator<=(float a, Fraction f);

        bool operator>=(Fraction a);

        bool operator>=(float a);

        friend bool operator>=(float a, Fraction f);

        bool operator>(Fraction a);

        bool operator>(float a);

        friend bool operator>(float a, Fraction f);

        bool operator<(Fraction a);

        bool operator<(float a);

        friend bool operator<(float a, Fraction f);

        Fraction operator++();

        Fraction operator++(int);

        Fraction operator--();

        Fraction operator--(int);

        friend ostream &operator<<(ostream &os, const Fraction &obj);

        friend istream &operator>>(istream &is, Fraction &obj);

    };


    int gcd(int a, int b);

    int lcm(int a, int b);

    Fraction floatToFractions(float number);

//    Fraction contraction(Fraction f);


    }