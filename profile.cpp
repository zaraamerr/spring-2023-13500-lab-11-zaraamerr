//Zara Amer
//Zamansky
//4/25
//Lab 11
//Task A: implement the class Profile that can store the info about a user of the network.
//It has two private properties of type string: displayname and username.
//The public interface consists of two constructors initializing the private variables and three functions:
// 1. getUsername returns the username.
// 2. getFullName returns the string in the format “displayname (@username)”.
// 3. setDisplayname allows to change the displayname property. 
//(Username is a unique user identifier and cannot change, while displayname can be any string and can be modified, so the class
//provides a mechanism for updating it.)

#include <iostream>
#include <string>
#include "profile.h"

Profile::Profile(std::string usrn, std::string dspn) {
    username = usrn;
    displayname = dspn;
}

Profile::Profile() {
    username = "";
    displayname = "";
}

std::string Profile::getUsername() {
    return username;
}

std::string Profile::getFullName() {
    return displayname + " (@" + username + ")";
}

void Profile::setDisplayName(std::string dspn) {
    displayname = dspn;
}

