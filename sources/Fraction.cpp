#include "Fraction.hpp"
#include <cmath>

using namespace std;

namespace ariel {

    Fraction::Fraction(int numerator, int denominator) {
        if(denominator == 0)
            throw logic_error("It is impossible to divide by 0");
        int myGcd = gcd(numerator, denominator);
        this->numerator = numerator / myGcd;
        this->denominator = denominator / myGcd;
    }


    Fraction Fraction::operator+(Fraction abc) {
        int d = lcm(this->denominator, abc.denominator);
        int u = (this->numerator * d / this->denominator) + (abc.numerator * d / abc.denominator);
        return Fraction(u, d);
    }

    Fraction Fraction::operator+(float abc) {
        Fraction s = floatToFractions(abc);
        return this->operator+(s);
    }

    Fraction operator+(float abc, Fraction fgh) {
        return fgh + abc;
    }

    Fraction Fraction::operator-(Fraction abc) {
        int d = lcm(this->denominator, abc.denominator);
        int u = (this->numerator * d / this->denominator) - (abc.numerator * d / abc.denominator);
        return Fraction(u, d);
    }

    Fraction Fraction::operator-(float abc) {
        Fraction s = floatToFractions(abc);
        return this->operator-(s);
    }

    Fraction operator-(float abc, Fraction fgh) {
        return fgh - abc;
    }

    Fraction Fraction::operator*(Fraction abc) {
        return Fraction(this->numerator * abc.numerator, this->denominator * abc.denominator);
    }

    Fraction Fraction::operator*(float abc) {
        Fraction s = floatToFractions(abc);
        return this->operator*(s);
    }

    Fraction operator*(float abc, Fraction fgh) {
        return fgh * abc;
    }

    Fraction Fraction::operator/(Fraction abc) {
        return this->operator*(Fraction(abc.denominator, abc.numerator));
    }

    Fraction Fraction::operator/(float abc) {
        Fraction s = floatToFractions(abc);
        return this->operator/(s);
    }

    Fraction operator/(float abc, Fraction fgh) {
        Fraction s = floatToFractions(abc);
        return s / fgh;
    }

    bool Fraction::operator==(Fraction abc) {
        return ((*this / abc).numerator == 1) &  ((*this / abc).denominator == 1);
    }

    bool Fraction::operator==(float abc) {
        Fraction f = floatToFractions(abc);
        return this->operator==(f);
    }

    bool operator==(float abc, Fraction fgh) {
        return fgh == abc;
    }

    bool Fraction::operator<=(Fraction abc) {
        return this->operator<(abc) or this->operator==(abc);
    }

    bool Fraction::operator<=(float abc) {
        Fraction f = floatToFractions(abc);
        return this->operator<=(f);

    }

    bool operator<=(float abc, Fraction fgh) {
        return fgh >= abc;
    }

    bool Fraction::operator>=(Fraction abc) {
        return this->operator>(abc) or this->operator==(abc);
    }

    bool Fraction::operator>=(float abc) {
        Fraction f = floatToFractions(abc);
        return this->operator>=(f);
    }

    bool operator>=(float abc, Fraction fgh) {
        return fgh <= abc;
    }

    bool Fraction::operator>(Fraction abc) {
        int myLcm = lcm(this->denominator, abc.denominator);
        return this->numerator * myLcm / this->denominator > abc.numerator * myLcm / abc.denominator;
    }

    bool Fraction::operator>(float abc) {
        Fraction f = floatToFractions(abc);
        return this->operator>(f);
    }

    bool operator>(float abc, Fraction fgh) {
        return fgh < abc;
    }

    bool Fraction::operator<(Fraction abc) {
        int myLcm = lcm(this->denominator, abc.denominator);
        return this->numerator * myLcm / this->denominator < abc.numerator * myLcm / abc.denominator;
    }

    bool Fraction::operator<(float abc) {
        Fraction f = floatToFractions(abc);
        return this->operator<(f);
    }

    bool operator<(float abc, Fraction fgh) {
        return fgh > abc;
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


    int gcd(int first, int second) {
        if (second == 0)
            return first;
        return ariel::gcd(second, first % second);
    }

    int lcm(int first, int second) {
        return abs(first * second) / ariel::gcd(first, second);
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

