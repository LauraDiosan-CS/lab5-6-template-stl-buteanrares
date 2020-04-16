//
// Created by butea on 4/9/2020.
//

#include "TestDomain.h"
#include <cassert>
#include <cstring>

TestDomain::TestDomain() {

}

TestDomain::~TestDomain() {

}

void TestDomain::test_domain() {
    Book b1("titlu1", "autor1", 2001);
    Book b2("titlu2", "autor2", 2002);
    assert(strcmp(b1.getTitle(), "titlu1") == 0);
    assert(strcmp(b1.getAuthor(), "autor1") == 0);
    assert(b1.getYear() == 2001);
    assert(!(b1 == b2));
    Book b5(b1);
    assert(b1 == b5);
    b1.setAuthor("rares");
    b1.setTitle("mytitle");
    b1.setYear(1999);
    assert(strcmp(b1.getTitle(), "mytitle") == 0);
    assert(strcmp(b1.getAuthor(), "rares") == 0);
    assert(b1.getYear() == 1999);
    b1.setIsRented("numePers");
    assert(strcmp(b1.getIsRented(), "numePers") == 0);
}
