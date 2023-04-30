#include "doctest.h"
#include "sources/Fraction.hpp"
#include "iostream"

using namespace ariel;
using namespace std;

TEST_CASE("Constructor Test"){
    CHECK_THROWS_AS_MESSAGE(Fraction(3,0) , logic_error , "It is impossible to divide by 0");
}

TEST_CASE("Basic Calculate Test"){
    Fraction a(1,2);
    Fraction b(8,9);
    Fraction c(4,11);

    // operator +
    CHECK(((a + b) == Fraction(25,18)));
    CHECK(((a + c) == Fraction(19,22)));

    // operator -
    CHECK(((a - b) == Fraction(-7,18)));
    CHECK(((b - c) == Fraction(52,99)));

    // operator *
    CHECK(((a * b) == Fraction(4,9)));
    CHECK(((b * c) == Fraction(32,99)));

    // operator /
    CHECK(((a / b) == Fraction(9,16)));
    CHECK(((a / c) == Fraction(11,8)));

    // operator ++
    CHECK(((a++) == Fraction(1,2)));
    CHECK(((c++) == Fraction(4 , 11)));

    // ++ operator
    CHECK(((++a) == Fraction(5,2)));
    CHECK(((++c) == Fraction(26 , 11)));

    // operator --
    CHECK(((a--) == Fraction(5,2)));
    CHECK(((b--) == Fraction(8 , 9)));

    // -- operator
    CHECK(((--a) == Fraction(1,2)));
    CHECK(((--b) == Fraction(-10 , 9)));

}


TEST_CASE("Compare Test"){
    Fraction a(3,5);
    Fraction b(7,3);
    CHECK((a == Fraction(6,10)));
    CHECK_FALSE((a == Fraction(8,9)));

    CHECK((a < b));
    CHECK_FALSE((b > Fraction(8,2)));

    CHECK_FALSE((a < Fraction(6,10)));
    CHECK_FALSE((a > Fraction(6,10)));
    CHECK((a >= Fraction(6,10)));
    CHECK((a <= Fraction(6,10)));


}

TEST_CASE("Same Expression Test"){
    Fraction a(6,7);
    Fraction b(-7,9);

    CHECK((a == Fraction(18,21)));
    CHECK((b == Fraction(7,-9)));
}

TEST_CASE("Order Of Operations Test"){
    Fraction a(5,8);
    Fraction b(2,3);
    Fraction c(1,9);

    CHECK((a + b / c  == Fraction(53,8)));
    CHECK(((a + b) / c  == Fraction(93,8)));
    CHECK((a * b / c == Fraction(15,4)));
    CHECK((a + c * b / c - a == b));
}

TEST_CASE("Errors Test"){
    Fraction a(5,9);
    CHECK_THROWS_AS_MESSAGE((a / Fraction(0,3)) , logic_error , "It is impossible to divide by 0");
    CHECK_THROWS_AS_MESSAGE((a / 0) , logic_error , "It is impossible to divide by 0");
    CHECK_NOTHROW(Fraction(0,3) / a);
    CHECK_NOTHROW(0 / a);
}


