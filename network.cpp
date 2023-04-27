//Zara Amer
//Zamansky
//4/25
//Lab 11
//Task B: The three main functionalities of the class Network are: 
//1) adding new users to the network
//2) following
//3) posting messages.
//For Task B, implement the first version of the class Network (feel free to copy your class Profile 
//and anything else from the previous program). This first version of the class should be able to add new users 
//and store their profiles, for that, the class has the following private variables:
// 1. an array of registered user profiles,
// 2. an integer numUsers, which stores the number of registered users.
// 3. the size of the profiles array is defined as MAX_USERS=20, we cannot sign up more than this number of users.
//The index in the array profile is the profile ID. As you keep adding new users, they are receiving ID = 0, 1, 2, and so on. 
//To look up the ID of a specific profile by its username, we have a private function findID(usrn), it should return the ID of
//the user with that username, or -1 if the user is not found in the profiles array.
//The public interface:
//a default constructor that creates an empty network. For now, setting numUsers = 0 is enough.
//addUser(usrn, dspn) is the central function for the class. It allows adding new users. This function receives the username and
//display name of a new user, the new user can be signed up only if the following conditions are met:
// 1. the new username usrn must be a non-empty alphanumeric string,
// 2. there is no other users in the network with the same username,
// 3. the array profiles is not full.
//If the above conditions are met, the new user should be added to the array profiles and the function should return true, 
//otherwise don’t add the user and return false, thus indicating that the operation failed.

#include <iostream>
#include <string>
#include "network.h"
#include "profile.h"

//Task C:
//The constructor Network() should be modified, setting all 
//elements of the matrix following to false, so in empty network no one is following anyone.
Network::Network() {
  numUsers = 0;
  for (int i = 0; i < MAX_USERS; i++) {
    for (int j = 0; j < MAX_USERS; j++) {
      following[i][j] = false;
    }
  }
}

int Network::findID(std::string usrn) {
  for (int i = 0; i < numUsers; i++) {
    if (profiles[i].getUsername() == usrn) {
      return i;
    }
  }
  return -1;
}

bool Network::addUser(std::string usrn, std::string dspn) {
  if (numUsers < MAX_USERS && findID(usrn) == -1 && usrn != "") {
    Profile p(usrn, dspn);
    profiles[numUsers] = p;
    numUsers++;
    return true;
  }
  return false;
}

//Task C: follow(usrn1, usrn2) simply marks the corresponding cell in the
//friendship matrix if both usernames are found. It returns true or false, depending on whether
//the operation was successful or not. Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
//return true if success (if both usernames exist), otherwise return false

bool Network::follow(std::string usrn1, std::string usrn2) {
  int id1 = findID(usrn1);
  int id2 = findID(usrn2);
  if (id1 != -1 && id2 != -1) {
    following[id1][id2] = true;
    return true;
  }
  return false;
}

// Print Dot file (graphical representation of the network)
void Network::printDot(){
    std::cout << "digraph {" << std::endl;
    for(int i = 0; i < MAX_USERS; i++){
        if(findID(profiles[i].getUsername()) != -1){
            std::cout << "    \"@" << profiles[i].getUsername() << "\"" << std::endl;
        }
    }
    std::cout << std::endl;
    for(int i = 0; i < MAX_USERS-1; i++){
        for(int j = 0; j < MAX_USERS-1; j++){
            if(following[i][j] == true){
                std::cout << "\"@" << profiles[i].getUsername() << "\"" << " -> " << "\"@" << profiles[j].getUsername() << "\"" << std::endl;
            }
        }
    }
    std::cout << "}" << std::endl;
}


