#include "Fraction.hpp"
#include <cmath>

using namespace std;

namespace ariel {

    Fraction::Fraction(int a, int b) {
        if(b == 0)
            throw logic_error("It is impossible to divide by 0");
        int myGcd = gcd(a, b);
        this->numerator = a / myGcd;
        this->denominator = b / myGcd;
    }


    Fraction Fraction::operator+(Fraction a) {
        int d = lcm(this->denominator, a.denominator);
        int u = (this->numerator * d / this->denominator) + (a.numerator * d / a.denominator);
        return Fraction(u, d);
    }

    Fraction Fraction::operator+(float a) {
        Fraction s = floatToFractions(a);
        return this->operator+(s);
    }

    Fraction operator+(float a, Fraction f) {
        return f + a;
    }

    Fraction Fraction::operator-(Fraction a) {
        int d = lcm(this->denominator, a.denominator);
        int u = (this->numerator * d / this->denominator) - (a.numerator * d / a.denominator);
        return Fraction(u, d);
    }

    Fraction Fraction::operator-(float a) {
        Fraction s = floatToFractions(a);
        return this->operator-(s);
    }

    Fraction operator-(float a, Fraction f) {
        return f - a;
    }

    Fraction Fraction::operator*(Fraction a) {
        return Fraction(this->numerator * a.numerator, this->denominator * a.denominator);
    }

    Fraction Fraction::operator*(float a) {
        Fraction s = floatToFractions(a);
        return this->operator*(s);
    }

    Fraction operator*(float a, Fraction f) {
        return f * a;
    }

    Fraction Fraction::operator/(Fraction a) {
        return this->operator*(Fraction(a.denominator, a.numerator));
    }

    Fraction Fraction::operator/(float a) {
        Fraction s = floatToFractions(a);
        return this->operator/(s);
    }

    Fraction operator/(float a, Fraction f) {
        Fraction s = floatToFractions(a);
        return s / f;
    }

    bool Fraction::operator==(Fraction a) {
      //  return this->numerator == a.numerator & this->denominator == a.denominator;
  return ((*this / a).numerator == 1) &  ((*this / a).denominator == 1);
    }

    bool Fraction::operator==(float a) {
        Fraction f = floatToFractions(a);
        return this->operator==(f);
    }

    bool operator==(float a, Fraction f) {
        return f == a;
    }

    bool Fraction::operator<=(Fraction a) {
        return this->operator<(a) or this->operator==(a);
    }

    bool Fraction::operator<=(float a) {
        Fraction f = floatToFractions(a);
        return this->operator<=(f);

    }

    bool operator<=(float a, Fraction f) {
        return f >= a;
    }

    bool Fraction::operator>=(Fraction a) {
        return this->operator>(a) or this->operator==(a);
    }

    bool Fraction::operator>=(float a) {
        Fraction f = floatToFractions(a);
        return this->operator>=(f);
    }

    bool operator>=(float a, Fraction f) {
        return f <= a;
    }

    bool Fraction::operator>(Fraction a) {
        int myLcm = lcm(this->denominator, a.denominator);
        return this->numerator * myLcm / this->denominator > a.numerator * myLcm / a.denominator;
    }

    bool Fraction::operator>(float a) {
        Fraction f = floatToFractions(a);
        return this->operator>(f);
    }

    bool operator>(float a, Fraction f) {
        return f < a;
    }

    bool Fraction::operator<(Fraction a) {
        int myLcm = lcm(this->denominator, a.denominator);
        return this->numerator * myLcm / this->denominator < a.numerator * myLcm / a.denominator;
    }

    bool Fraction::operator<(float a) {
        Fraction f = floatToFractions(a);
        return this->operator<(f);
    }

    bool operator<(float a, Fraction f) {
        return f > a;
    }

    Fraction Fraction::operator++() {
        this->numerator += this->denominator;
        return *this;
    }

    Fraction Fraction::operator++(int) {
        Fraction temp(*this);
        this->numerator += this->denominator;
        return temp;
    }

    Fraction Fraction::operator--() {
        this->numerator -= this->denominator;
        return *this;
    }

    Fraction Fraction::operator--(int) {
        Fraction temp(*this);
        this->numerator -= this->denominator;
        return temp;
    }

    ostream &operator<<(ostream &os, const Fraction &obj) {
        return os << " " << obj.numerator << "/" << obj.denominator;
    }

    istream &operator>>(istream &is, Fraction &obj) {
        return is >> obj.numerator >> obj.denominator;
    }


    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return ariel::gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return abs(a * b) / ariel::gcd(a, b);
    }

    Fraction floatToFractions(float number) {
        int num = round(number * 1000000); // multiply by 1 million to preserve precision
        int den = 1000000;
        int gcd_ = ariel::gcd(num, den); // use the built-in gcd function to simplify the fraction
        num /= gcd_;
        den /= gcd_;
        return Fraction(num, den);
    }
}

//Fraction contraction(Fraction a){
//    int myGcd = ariel::gcd(a.numerator , a.denominator);
//    a.numerator /= myGcd;
//    a.denominator /= myGcd;
//    return a;
//
//}
