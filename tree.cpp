#include "tree.h"
using namespace std;

//Molina Nhoung, CS163, 5/23/23, Program 4
//The purpose of this file is to implement the wrapper and recursive functions for the
//bst class. This allows other programmers to examine how the functions would work
//and how to use this to interact with the client. The wrapper function allows the before and after
//recursion so fully implement the recursion aspects.

//constructor that will initialize the data members
table::table()
{}
//destructor to deallocate the data members
table::~table()
{}
//add a travel item that's passed in as an argument and add it to the hash table
int table::insert(const client & to_key)
{}
//recursive call for inserting
int table::insert(node * & root, const client & to_key)
{}
//display all travel information
int table::display_all() const
{}
//recursive call for displaying all
int table::display_all(node * root) const
{}
//remove by the locatin name
int table::remove_location(char location[])
{}
//recursive call to remove an item
int table::remove_location(node * & root, char location[])
{}
//retrieve the information from the particular location name match
int table::retrieve_match_name(char match[], travel & find)
{}
//recursive call to retrieve from the list
int table::retrieve_match_name(node * root, char match[], travel & find)
{}
//display by the seasonal match
int table::display_match_time(char season[]) const
{}
//recursive call to display by the seasonal match
int table::display_match_time(node * root, char season[])
{}
//evaluate the height of the tree
int table::height() const
{}
//recursive call to evaluate the height of the tree
int table::height(node * root) const
{}
