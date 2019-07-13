/*
Name: Professor Sowell
Date: April 27, 2019
Class: COMP 142
Project 5: The Social Network
Pledge: I have neither given nor received unauthorized aid on this program.
Description: network.h
*/
#ifndef NETWORK_H
#define NETWORK_H
#include "user.h"
#include <vector>
using namespace std;

class Network {
public:
  // Constructor.
  Network();
  // Dstructor.
  // ~Network();
  int read_friends(const char *filename);
  int write_friends(const char *filename);
  void add_user(string username, int yr, int zipcode);
  int add_connection(string name1, string name2);
  int remove_connection(string name1, string name2);
  int get_id(string username);
  const void print_users();
  const void list_friends(string username);

private:
  vector<User> users;
};

#endif
