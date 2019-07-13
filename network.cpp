/*
Name: Professor Sowell
Date: April 27, 2019
Class: COMP 142
Project 5: The Social Network
Pledge: I have neither given nor received unauthorized aid on this program.
Description: network.cpp
*/
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "network.h"

Network::Network() {} // Constructor.

//Network::~Network() {} // Destructor.

// Function that initializes all of the network’s information from a file.
int Network::read_friends(const char *filename) {
  // Define ifstream.
  ifstream inFS;
  inFS.open(filename);

  // If there is I/O error return -1.
  if (!inFS.is_open())
    return -1;

  // Define info variables.
  int n;
  int id, year, zip;
  string first, last;
  string strFriends;

  int friendID;

  inFS >> n;

  for (int i = 0; i < n; i++) {
    //Reading user's information.
    inFS >> id >> first >> last >> year >> zip;
    string name = first + ' ' + last;

    // Create new user.
    User curr_user(id, name, year, zip);

    getline(inFS, strFriends); // move past the newline
    getline(inFS, strFriends);

    // Stream the friend list.
    stringstream ss(strFriends);

    // Read each friend id in the stream of friend list.
    while (ss >> friendID) {
      // Add friend to the current user.
      curr_user.add_friend(friendID);
    }

    // Add user to the network.
    users.push_back(curr_user);
  }

  inFS.close();
  return 0;
}

// Function that writes all of the network’s information to a file.
int Network::write_friends(const char *filename) {
// Define ostream.
  //cout << "goodbye" << endl;
  ofstream outFS;
  outFS.open(filename);

  // If there is an I/O error return -1.
  if (!outFS.is_open())
    return -1;

  // Define info variables.
  int n = users.size(); // number of users
  int id, year, zip;
  string first, last, name;
  vector<int> friends;

  outFS << n << "\n";

  // Goes through each user.
  for (int i = 0; i < n; i++) {
    id = users[i].getId();
    year = users[i].getYear();
    name = users[i].getName();
    zip = users[i].getZip();

    // Prints user information.
    friends = *(users[i].getFriends());
    outFS << id << "\n\t" << name << "\n\t" << year << "\n\t" << zip << "\n\t";

    for (int id : friends) { // friends vector
      outFS << id << ' ';
    }

    outFS << "\n";
  }

  outFS.close();
  return 0;
}

// Function to add a User to the Network database.
void Network::add_user(std::string username, int yr, int zipcode) {
  // Boolean test
  bool test = false;
  int id = users.size();
  User new_user = User(id, username, yr, zipcode);

  for (int i = 0; i < users.size(); i++) {
    if (users[i].getName() == username && users[i].getZip() == zipcode && users[i].getYear() == yr) {
      test = true;
    }
  }

  // Checks if user is already in the database.
  if (test == false) {
    users.push_back(new_user);
  }

  else {
    cout << "Error: User is already in database" << endl;
  }

}

// Function accepting two strings corresponding to the names of the Users to make friends.
int Network::add_connection(std::string name1, std::string name2) {
  // Check if two names are the same.
  if (name1 == name2) {
    return -1;
    cout << "Error: Two names are the same" << endl;
  }

  // Check if format is correct: first + ' ' + last.
  if (name1.substr(name1.find(' '), name1.length()).length() <= 0 || \
      name2.substr(name2.find(' '), name2.length()).length() <= 0) {
    return -1;
    cout << "Error: Name format is incorrect" << endl;
  }

  int id1 = -1; // default index.
  int id2 = -1; // default index.

  for (User u : users) {
    if (u.getName() == name1) {
      id1 = u.getId();
    }
    else if (u.getName() == name2) {
      id2 = u.getId();
    }
  }

  // Check if one or both names are not in the database.
  if (id1 == -1 || id2 == -1) {
    return -1;
    cout << "Error: One or both names are not in the database" << endl;
  }

  // If everything is correct.
  users[id1].add_friend(id2);
  users[id2].add_friend(id1);

  return 0;
}

// Function accepting two strings of the names of Users to delete the friend connection between.
int Network::remove_connection(std::string name1, std::string name2) {
  // Check if two names are the same.
  if (name1 == name2) {
    return -1;
    cout << "Error: Two names are the same" << endl;
  }

  // Check if format is correct: first + ' ' + last.
  if (name1.substr(0, name1.find(' ')).length() <= 0 || \
      name2.substr(0, name2.find(' ')).length() <= 0) {
    return -1;
    cout << "Error: Name format is incorrect" << endl;
  }

  int id1 = -1; // default index.
  int id2 = -1; //default index.

  for (User u : users) {
    if (u.getName() == name1) {
      id1 = u.getId();
    }
    else if (u.getName() == name2) {
      id2 = u.getId();
    }
  }

  // Check if one or both names are not in the database.
  if (id1 == -1 || id2 == -1) {
    return -1;
    cout << "Error: One or both names are not in the database" << endl;
  }

  // If everything is correct.
  users[id1].delete_friend(id2);
  users[id2].delete_friend(id1);

  return 0;
}

// Function accepting a user name and returning the corresponding ID for that user.
int Network::get_id(std::string username) {
  // Check if format is correct: first + ' ' + last.
  if (username.substr(0, username.find(' ')).length() <= 0) {
    return -1;
    cout << "Error: Name format is incorrect" << endl;
  }

  // Default -1 if not found.
  int id = -1;
  for (User u : users) {
    if (u.getName() == username) {
      id = u.getId();
      break;
    }
  }

  return id;
}

// Function returns list of users.
const void Network::print_users() {
  cout << "ID      Name            Year     Zip" << endl;
  cout << "===========================================================" << endl;

  for (int i = 0; i < users.size() ; i++) {
    User u = users[i];
    // Retrieve user information.
    cout << i << ".\t" << u.getName() << "\t" << u.getYear() << "\t" << u.getZip() << endl;
  }

  return;
}

//Function returns list of friends.
const void Network::list_friends(string username) {
  cout << "ID      Name            Year     Zip" << endl;
  cout << "===========================================================" << endl;

  // Gets user information.
  int id = get_id(username);
  if (id == -1) {
    cout << "User not exist in the database" << endl;
    return;
  }

  User u = users[id];
  vector<int> friends = *(u.getFriends());
  for (int i : friends) {
    // Retrieve friend information.
    User f = users[i];
    cout << f.getId() << ".\t" << f.getName() << "\t" << f.getYear() << "\t" << f.getZip() << endl;
  }
}
