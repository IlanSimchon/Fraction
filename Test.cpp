#include "doctest.h"
#include "sources/Fraction.hpp"
#include "iostream"

using namespace ariel;
using namespace std;

TEST_CASE("Constructor Test"){
    CHECK_THROWS_AS_MESSAGE(Fraction(3,0) , logic_error , "It is impossible to divide by 0");
}

TEST_CASE("Basic Calculate Test"){
    Fraction abc(1,2);
    Fraction bcd(8,9);
    Fraction cde(4,11);

    // operator +
    CHECK(((abc + bcd) == Fraction(25,18)));
    CHECK(((abc + cde) == Fraction(19,22)));

    // operator -
    CHECK(((abc - bcd) == Fraction(-7,18)));
    CHECK(((bcd - cde) == Fraction(52,99)));

    // operator *
    CHECK(((abc * bcd) == Fraction(4,9)));
    CHECK(((bcd * cde) == Fraction(32,99)));

    // operator /
    CHECK(((abc / bcd) == Fraction(9,16)));
    CHECK(((abc / cde) == Fraction(11,8)));

    // operator ++
    CHECK(((abc++) == Fraction(1,2)));
    CHECK(((cde++) == Fraction(4 , 11)));

    // ++ operator
    CHECK(((++abc) == Fraction(5,2)));
    CHECK(((++cde) == Fraction(26 , 11)));

    // operator --
    CHECK(((abc--) == Fraction(5,2)));
    CHECK(((bcd--) == Fraction(8 , 9)));

    // -- operator
    CHECK(((--abc) == Fraction(1,2)));
    CHECK(((--bcd) == Fraction(-10 , 9)));

}


TEST_CASE("Compare Test"){
    Fraction abc(3,5);
    Fraction bcd(7,3);
    CHECK((abc == Fraction(6,10)));
    CHECK_FALSE((abc == Fraction(8,9)));

    CHECK((abc < bcd));
    CHECK_FALSE((bcd > Fraction(8,2)));

    CHECK_FALSE((abc < Fraction(6,10)));
    CHECK_FALSE((abc > Fraction(6,10)));
    CHECK((abc >= Fraction(6,10)));
    CHECK((abc <= Fraction(6,10)));


}

TEST_CASE("Same Expression Test"){
    Fraction abc(6,7);
    Fraction bcd(-7,9);

    CHECK((abc == Fraction(18,21)));
    CHECK((bcd == Fraction(7,-9)));
}

TEST_CASE("Order Of Operations Test"){
    Fraction abc(5,8);
    Fraction bcd(2,3);
    Fraction cde(1,9);

    CHECK((abc + bcd / cde  == Fraction(53,8)));
    CHECK(((abc + bcd) / cde  == Fraction(93,8)));
    CHECK((abc * bcd / cde == Fraction(15,4)));
    CHECK((abc + cde * bcd / cde - abc == bcd));
}

TEST_CASE("Errors Test"){
    Fraction abc(5,9);
    CHECK_THROWS_AS_MESSAGE((abc / Fraction(0,3)) , logic_error , "It is impossible to divide by 0");
    CHECK_THROWS_AS_MESSAGE((abc / 0) , logic_error , "It is impossible to divide by 0");
    CHECK_NOTHROW(Fraction(0,3) / abc);
    CHECK_NOTHROW(0 / abc);
}


