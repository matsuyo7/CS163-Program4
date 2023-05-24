#include "tree.h"
using namespace std;

//Molina Nhoung, CS163, 5/23/23, Program 4
//The purpose of this file is to implement the travel class that deals with the individual data
//and the client class together. This allows other programers to examine this file to help output
//what to give to the user and what to take from them.

//constructor
travel::travel()
{}
//destructor
travel::~travel()
{}
//create information from the client
int travel::create(const client & to_copy)
{}
//copy information to be inserted
int travel::copy(const travel & to_add)
{}
//display a travel information
int travel::display() const
{}
//find a match with the name and return true
int travel::find(char match[]) const
{}
//retrieve travel information from the matching name
int travel::retrieve(char match[], travel & find) const
{}
