//Zara Amer
//Zamansky
//4/25
//Lab 11

#include <iostream>
#include <string>
#include "profile.h"
#include "network.h"

int main() {
    Profile p1("marco", "Marco");    
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    std::cout << p2.getUsername() << std::endl; // tarma1
    std::cout << p2.getFullName() << std::endl; // Tarma Roving (@tarma1)

    Network nw;
    std::cout << nw.addUser("mario", "Mario") << std::endl;     // true (1)
    std::cout << nw.addUser("luigi", "Luigi") << std::endl;     // true (1)

    std::cout << nw.addUser("mario", "Mario2") << std::endl;  // false (0) b/c there are other users in the network w/ the usrn "mario"
    std::cout << nw.addUser("mario 2", "Mario2") << std::endl;  // false (0) b/c the username contains a space
    std::cout << nw.addUser("mario-2", "Mario2") << std::endl;  // false (0) b/c the username contains a non-alphanumeric character

    for(int i = 2; i < 20; i++)
        std::cout << nw.addUser("mario" + std::to_string(i), 
                 "Mario" + std::to_string(i)) << std::endl;   // true (1)

    std::cout << nw.addUser("yoshi", "Yoshi") << std::endl; //false (0) bc the array is full and exceeds max users
   
    Network nw2;
    nw2.addUser("mario", "Mario");
    nw2.addUser("luigi", "Luigi");
    nw2.addUser("yoshi", "Yoshi");
    // make them follow each other
    nw2.follow("mario", "luigi");
    nw2.follow("mario", "yoshi");
    nw2.follow("luigi", "mario");
    nw2.follow("luigi", "yoshi");
    nw2.follow("yoshi", "mario");
    nw2.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw2.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        std::string usrn = "mario" + std::to_string(i);
        std::string dspn = "Mario " + std::to_string(i);
        nw2.addUser(usrn, dspn);
        nw2.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw2.follow("mario2", "luigi");

    nw2.printDot();
}
