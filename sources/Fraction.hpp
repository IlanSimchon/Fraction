
namespace  ariel {

    class Fraction {
    public:
        int mone;
        int mechane;
    Fraction(int a , int b);

    Fraction operator+(Fraction a);
    Fraction operator-(Fraction a);
    Fraction operator*(Fraction a);
    Fraction operator/(Fraction a);
    bool operator==(Fraction a);
    bool operator<=(Fraction a);
    bool operator>=(Fraction a);
    bool operator>(Fraction a);
    bool operator<(Fraction a);
    Fraction operator++();
    Fraction operator--();
    Fraction operator<<(Fraction a);
    Fraction operator>>(Fraction a);




    };

}