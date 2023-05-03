#include "iostream"
using namespace  std;
namespace  ariel {

    class Fraction {
    private:
        int numerator;
        int denominator;
    public:
        Fraction(int numerator, int denominator);

        Fraction(float frac);

        Fraction();

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

        bool operator==(const Fraction &abc) const;

        bool operator==(float abc);

        friend bool operator==(float abc, Fraction fgh);

        bool operator!=(const Fraction &abc) const;

        friend bool operator!=(float abc,  Fraction fgh);

        bool operator<=(const Fraction &abc) const;

        bool operator<=(float abc);

        friend bool operator<=(float abc, Fraction fgh);

        bool operator>=(const Fraction &abc) const;

        bool operator>=(float abc);

        friend bool operator>=(float abc, Fraction fgh);

        bool operator>(const Fraction &abc) const;

        bool operator>(float abc);

        friend bool operator>(float abc, Fraction fgh);

        bool operator<(const Fraction &abc) const;

        bool operator<(float abc);

        friend bool operator<(float abc, Fraction fgh);

        Fraction operator++();

        Fraction operator++(int);

        Fraction operator--();

        Fraction operator--(int);

        friend ostream &operator<<(ostream &osb, const Fraction &obj);

        friend istream &operator>>(istream &isb, Fraction &obj);

        int getNumerator();

        int getDenominator();

    };

    bool add_overflow(int first , int second);

    bool sub_overflow(int first, int second);

    bool mul_overflow(Fraction abc ,  Fraction cbd);

    bool div_overflow(Fraction abc ,  Fraction cbd);

    int gcd(int first, int second);

    int lcm(int first, int second);

    Fraction floatToFractions(float number);

    }

