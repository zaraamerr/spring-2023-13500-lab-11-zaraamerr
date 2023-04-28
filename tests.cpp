#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

//add your tests here

TEST_CASE("Username and Full Name Tests")
{
    Profile p1("marco", "Marco");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco (@marco)");

    p1.setDisplayName("Marco Rossi");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco Rossi (@marco)");

    Profile p2("tarma1", "Tarma Roving");
    CHECK(p2.getUsername() == "tarma1");
    CHECK(p2.getFullName() == "Tarma Roving (@tarma1)"); 
}

TEST_CASE("Bool addUser and Follow Tests")
{
    Network nw;
    CHECK(nw.addUser("mario", "Mario") == 1);
    CHECK(nw.addUser("luigi", "Luigi") == 1);

    CHECK(nw.addUser("mario", "Mario2") == 0);
    CHECK(nw.addUser("mario", "Mario3") == 0); 
    CHECK(nw.addUser("mario", "Mario4") == 0);
}

TEST_CASE("Bool Follow Tests")
{
    Network nw;
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    CHECK(nw.follow("mario", "luigi") == 1);
    CHECK(nw.follow("mario", "yoshi") == 1);
    CHECK(nw.follow("luigi", "mario") == 1);
    CHECK(nw.follow("luigi", "yoshi") == 1);
    CHECK(nw.follow("yoshi", "mario") == 1);
    CHECK(nw.follow("yoshi", "luigi") == 1);
}


