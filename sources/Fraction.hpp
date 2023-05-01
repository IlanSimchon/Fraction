#include "iostream"
using namespace  std;
namespace  ariel {

    class Fraction {
    public:
        int numerator;
        int denominator;

        Fraction(int numerator, int denominator);

        Fraction operator+(Fraction abc);

        Fraction operator+(float abc);

        friend Fraction operator+(float abc, Fraction fgh);

        Fraction operator-(Fraction abc);

        Fraction operator-(float abc);

        friend Fraction operator-(float abc, Fraction fgh);

        Fraction operator*(Fraction abc);

        Fraction operator*(float abc);

        friend Fraction operator*(float abc, Fraction fgh);

        Fraction operator/(Fraction abc);

        Fraction operator/(float abc);

        friend Fraction operator/(float abc, Fraction fgh);

        bool operator==(Fraction abc);

        bool operator==(float abc);

        friend bool operator==(float abc, Fraction fgh);

        bool operator<=(Fraction abc);

        bool operator<=(float abc);

        friend bool operator<=(float abc, Fraction fgh);

        bool operator>=(Fraction abc);

        bool operator>=(float abc);

        friend bool operator>=(float abc, Fraction fgh);

        bool operator>(Fraction abc);

        bool operator>(float abc);

        friend bool operator>(float abc, Fraction fgh);

        bool operator<(Fraction abc);

        bool operator<(float abc);

        friend bool operator<(float abc, Fraction fgh);

        Fraction operator++();

        Fraction operator++(int);

        Fraction operator--();

        Fraction operator--(int);

        friend ostream &operator<<(ostream &osb, const Fraction &obj);

        friend istream &operator>>(istream &isb, Fraction &obj);

    };


    int gcd(int first, int second);

    int lcm(int first, int second);

    Fraction floatToFractions(float number);


    }