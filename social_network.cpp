/*
Name: Professor Sowell
Date: April 27, 2019
Class: COMP 142
Project 5: The Social Network
Pledge: I have neither given nor received unauthorized aid on this program.
Description: Program that models a social network, allowing users to be added,
            friend connections made, etc.
*/
#include "user.h"
#include "network.h"
#include <iostream>

int main(int argc, char *argv[]) {
  int option, zip, birth;
  string first1, last1, first2, last2, name1, name2, filename;

  // Read files.
  Network network;
  network.read_friends(argv[1]);

  // Prints options.
  cout << "PROGRAM OPTIONS" << endl;
  cout << "1: Add a user" << endl;
  cout << "2: Add friend connection" << endl;
  cout << "3: Remove friend connection" << endl;
  cout << "4: Print users" << endl;
  cout << "5: List friends" << endl;
  cout << "6: Write to file" << endl;
  cout << "Any Other Number: Exit Program" << endl;

  // Read first option.
  cin >> option;

  // Exits program on ANY invalid command numbers.
  while (option <= 6 && option >= 1 ) {
    // If option 1: Add a user.
    if(option == 1) {
      string first, last;
      int birth, zip;

      //cout << "User's first name: ";
      cin >> first1;
      //cout << "User's last name: ";
      cin >> last1;
      //cout << "User's birth year: ";
      cin >> birth;
      //cout << "User's zipcode: ";
      cin >> zip;

      name1 = first1 + " " + last1;

      network.add_user(name1, birth, zip);
      cout << "Added " << name1 << " to the databse" << endl;
    }

    // If option 2: Add friend connection.
    if(option == 2) {
      //cout << "First User's first name: ";
      cin >> first1;
      //cout << "First User's last name: ";
      cin >> last1;
      //cout << "Second User's first name: ";
      cin >> first2;
      //cout << "Second User's last name: ";
      cin >> last2;

      name1 = first1 + " " + last1;
      name2 = first2 + " " + last2;


      int success = network.add_connection(name1, name2);
      if (success != -1)
        cout << "Added connection between " << name1 << " and " << name2 << endl;
    }

    // If option 3: remove friend connection.
    if(option == 3) {
      //cout << "First User's first name: ";
      cin >> first1;
      //cout << "First User's last name: ";
      cin >> last1;
      //cout << "Second User's first name: ";
      cin >> first2;
      //cout << "Second User's last name: ";
      cin >> last2;

      name1 = first1 + " " + last1;
      name2 = first2 + " " + last2;

      int success = network.remove_connection(name1, name2);
      if (success != -1)
        cout << "Removed connection between " << name1 << " and " << name2 << endl;
    }

    // If option 4: Print number of users.
    if(option == 4) {
      network.print_users();
    }

    //If option 5: List friends.
    if(option == 5) {
      //cout << "User's first name: ";
      cin >> first1;
      //cout << "User's last name: ";
      cin >> last1;
      network.list_friends(first1 + ' ' + last1);
;    }

    // If option 6: Write to file.
    if(option == 6) {
      //cout << "File name: ";
      cin >> filename;

      // Convert the string file to a *char.
      char *cstr = &filename[0u];
      //cout << "Hello" << endl;
      network.write_friends(cstr);
    }

    cout << "PROGRAM OPTIONS" << endl;
    cout << "1: Add a user" << endl;
    cout << "2: Add friend connection" << endl;
    cout << "3: Remove friend connection" << endl;
    cout << "4: Print users" << endl;
    cout << "5: List friends" << endl;
    cout << "6: Write to file" << endl;
    cout << "Any Other Number: Exit Program" << endl;

    // Read the next option.
    cin >> option;
  }
}
