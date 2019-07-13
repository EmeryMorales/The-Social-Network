/*
Name: Professor Sowell
Date: April 27, 2019
Class: COMP 142
Project 5: The Social Network
Pledge: I have neither given nor received unauthorized aid on this program.
Description: user.h
*/
#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
using namespace std;

// Define a class to model a User.
class User {
private:
  int id; // An integer id.
  string name; // A user name with first and last name separated by spaces.
  int year; // An integer indicating the birth year of the user.
  int zip; // An integer indicating the user’s zip code.
  vector<int> friends; // A list of integer entries for friend connections.

public:
  User(int user_id, string user_name, int user_year, int user_zip);
  void add_friend(int id);
  void delete_friend(int id);
  int getId();
  string getName();
  int getYear();
  int getZip();
  vector<int>* getFriends();
  ~User();
};

#endif
