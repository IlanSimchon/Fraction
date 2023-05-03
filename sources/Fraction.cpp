#include "Fraction.hpp"
#include <cmath>
#include <limits>

using namespace std;
namespace ariel {

    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    Fraction::Fraction(int numerator, int denominator) {
        if(denominator == 0)
            throw invalid_argument("It is impossible to divide by 0");

        int myGcd = gcd(numerator, denominator);
        this->numerator = numerator / myGcd;
        this->denominator = denominator / myGcd;

        if(this->denominator < 0) {
            this->numerator *= -1;
            this->denominator *= -1;
        }
    }

    Fraction::Fraction(float frac){
        frac = round(frac * 1000) / 1000;
        Fraction f = floatToFractions(frac);
        this->numerator = f.getNumerator();
        this->denominator = f.getDenominator();
    }

    Fraction::Fraction(){
        this->numerator = 1;
        this->denominator = 1;
    }

    Fraction Fraction::operator+(Fraction abc) {
        int d = lcm(this->denominator, abc.denominator);
        int u1 = (this->numerator * d / this->denominator);
        int u2 = (abc.numerator * d / abc.denominator);

        if(add_overflow(u1,u2))
            throw overflow_error("");

        return Fraction(u1+u2, d);
    }

    Fraction Fraction::operator+(float abc) {
        abc = round(abc * 1000) / 1000;
        Fraction s = floatToFractions(abc);

        return this->operator+(s);
    }

    Fraction operator+(float abc, Fraction fgh) {
        abc = round(abc * 1000) / 1000;

        return fgh + abc;
    }

    Fraction Fraction::operator-(Fraction abc) {
        int d = lcm(this->denominator, abc.denominator);
        int u1 = (this->numerator * d / this->denominator);
        int u2 = (abc.numerator * d / abc.denominator);

        if(sub_overflow(u1,u2))
            throw overflow_error("");

        return Fraction(u1-u2, d);
    }

    Fraction Fraction::operator-(float abc) {
        return this->operator-(Fraction(abc));
    }

    Fraction operator-(float abc, Fraction fgh) {
        return Fraction(abc) - fgh;
    }

    Fraction Fraction::operator*(Fraction abc) {
        if(mul_overflow(*this , abc))
            throw overflow_error("");

        Fraction fgh(this->numerator * abc.numerator, this->denominator * abc.denominator);

        return fgh;
    }

    Fraction Fraction::operator*(float abc) {
        return this->operator*(Fraction(abc));
    }

    Fraction operator*(float abc, Fraction fgh) {
        return fgh * abc;
    }

    Fraction Fraction::operator/(Fraction abc) {
        if(div_overflow(*this , abc))
            throw overflow_error("");

        if(abc.numerator == 0)
            throw runtime_error("");

        return this->operator*(Fraction(abc.denominator, abc.numerator));
    }

    Fraction Fraction::operator/(float abc) {
        return this->operator/(Fraction(abc));
    }

    Fraction operator/(float abc, Fraction fgh) {
        return Fraction(abc) / fgh;
    }

    bool Fraction::operator==(const Fraction &abc) const {
        return this->numerator == abc.numerator && this->denominator == abc.denominator;
    }

    bool Fraction::operator==(float abc) {
        return this->operator==(Fraction(abc));
    }

    bool operator==(float abc, Fraction fgh) {
        return fgh == abc;
    }
    bool Fraction::operator!=(const Fraction &abc) const{
        return ! (*this == abc);
    }

    bool operator!=(float abc,  Fraction fgh){
        return !(floatToFractions(abc) == fgh);
    }

    bool Fraction::operator<=(const Fraction &abc) const {
        return this->operator<(abc) or this->operator==(abc);
    }

    bool Fraction::operator<=(float abc) {
        return this->operator<=(Fraction(abc));

    }

    bool operator<=(float abc, Fraction fgh) {
        return Fraction(abc) <= fgh;
    }

    bool Fraction::operator>=(const Fraction &abc) const {
        return this->operator>(abc) or this->operator==(abc);
    }

    bool Fraction::operator>=(float abc) {
        return this->operator>=(Fraction(abc));
    }

    bool operator>=(float abc, Fraction fgh) {
        return Fraction(abc) >= fgh;
    }

    bool Fraction::operator>(const Fraction &abc) const {
        int myLcm = lcm(this->denominator, abc.denominator);
        return this->numerator * myLcm / this->denominator > abc.numerator * myLcm / abc.denominator;
    }

    bool Fraction::operator>(float abc) {
        return this->operator>(Fraction(abc));
    }

    bool operator>(float abc, Fraction fgh) {
        return Fraction(abc) > fgh;
    }

    bool Fraction::operator<(const Fraction &abc) const{
        int myLcm = lcm(this->denominator, abc.denominator);
        return this->numerator * myLcm / this->denominator < abc.numerator * myLcm / abc.denominator;
    }

    bool Fraction::operator<(float abc) {
        return this->operator<(Fraction(abc));
    }

    bool operator<(float abc, Fraction fgh) {
        return Fraction(abc) < fgh;
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

    ostream &operator<<(ostream &osb, const Fraction &obj) {
        return osb  << obj.numerator << "/" << obj.denominator;
    }


    istream &operator>>(istream &isb, Fraction &obj) {

        isb >> obj.numerator >> obj.denominator;

        if(obj.denominator == 0)
            throw runtime_error("It is impossible to divide by 0");
        obj = Fraction(obj.numerator , obj.denominator);

        if(! isb)
            throw runtime_error("");
        return isb;
    }

    int Fraction::getNumerator(){
        return this->numerator;
    }

    int Fraction::getDenominator(){
        return this->denominator;
    }

    bool add_overflow(int first , int second) {
        if (second > 0 && first > max_int - second) {
            return true;
        }
        if (second < 0 && first < min_int - second)
            return true;
        return false;
    }

    bool sub_overflow(int first, int second) {
        if ((second < 0 && first > max_int + second) || (second > 0 && first < min_int + second)) {
            return true;
        }
        return false;
    }

    bool mul_overflow(Fraction abc ,  Fraction cbd) {
        long n = long(abc.getNumerator()) * cbd.getNumerator();
        long d = long(abc.getDenominator()) * cbd.getDenominator();
        if (n > max_int || d > max_int || n < min_int || d < min_int) {
            return true;
        }
        return false;
    }

    bool div_overflow(Fraction abc ,  Fraction cbd) {
        long n = long(abc.getNumerator()) * cbd.getDenominator();
        long d = long(abc.getDenominator()) * cbd.getNumerator();
        if (n > max_int || d > max_int || n < min_int || d < min_int) {
            return true;
        }
        return false;
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



