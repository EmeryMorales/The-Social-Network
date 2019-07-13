/*
Name: Professor Sowell
Date: April 27, 2019
Class: COMP 142
Project 5: The Social Network
Pledge: I have neither given nor received unauthorized aid on this program.
Description: user.cpp
*/
#include <algorithm>
#include "user.h"

// Constructor.
User::User(int user_id, string user_name, int user_year, int user_zip) {
  id = user_id;
  name = user_name;
  year = user_year;
  zip = user_zip;
}

// Function accepting the ID of a user to add as a friend.
void User::add_friend(int id) {
  // If id is already a friend do nothing.
  if (std::find(friends.begin(), friends.end(), id) != friends.end())
    return;

  friends.push_back(id);
  return;
}

// Function accepting the ID of a user to delete as a friend.
void User::delete_friend(int id) {
  // If id is not a friend do nothing.
  // if (std::find(friends.begin(), friends.end(), id) == friends.end())
  //     return;
  friends.erase(remove(friends.begin(), friends.end(), id), friends.end());
  return;
}

/* Individual accessor functions to return the user’s name, their user ID, birth
year, and zip code. */

int User::User::getId() { return id; }

string User::User::getName() { return name; }

int User::User::getYear() { return year; }

int User::getZip() { return zip; }

// A pointer or reference to the friend list (array or vector).
vector<int>* User::getFriends() { return &friends; }

// Destructor.
User::~User() {}
