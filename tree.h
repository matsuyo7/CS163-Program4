#include <iostream>
#include <cctype>
#include <cstring>

//Molina Nhoung, CS163, 5/23/23, Program 4
//The purpose of this file is to create a binary search tree table ADT
//where each node will have the travel class information stored.
//The data organized will allow other programmers to examine the file to
//allow the user to manipulate their own travel location.

const int SIZE {200};	//constant size for static arrays

struct client
{
	char c_name[SIZE];	//user input name of the location
	char c_country[SIZE];	//user input state and country
	char c_attract[SIZE];	//user input attraction
	char c_time[SIZE];	//user input best time of year
	char c_transport[SIZE];	//user input how to get there
	char c_notes[SIZE];	//user input important information to know about
};

class travel
{
	public:
		travel();	//constructor
		~travel();	//destructor
		int create(const client & to_copy);	//create information from the client
		int display() const;	//display a travel information
		int find(char match[]) const;	//find a match with the name and return true
		int retrieve(char match[], travel & find) const;	//retrieve travel information from the matching name
		int compare(const char match[]);	//compare the data to add and the data already stored to know if to store left or right
	private:
		char * name;	//name of the location
		char * country;	//state/city and country
		char * attract;	//best things to do there
		char * time;	//best time of year
		char * transport;	//how to get there
		char * notes;	//important notes to know about
};

struct node
{
	travel trip;	//object for one travel item
	node * left;
	node * right;
};

class table
{
	public:
		table();	//constructor
		~table();	//destructor
		int insert(const client & to_add);	//add a travel item that's passed in as an argument and add it to the BST
		int display_all() const;	//display all travel information
		int remove_location(char location[]);	//remove by the locatin name
		int retrieve_match_name(char match[], travel & find);	//retrieve the information from the particular location name match
		int display_match_time(char season[]) const;	//display by the seasonal match
		int height() const;	//evaluate the height of the tree
	private:
		node * root;
		int insert(node * & root, const client & to_add);	//recursive call for inserting
		int display_all(node * root) const;	//recursive call for displaying all
		int remove_location(node * & root, char location[]);	//recursive call to remove an item
		int retrieve_match_name(node * root, char match[], travel & find);	//recursive call to retrieve from the list
		int display_match_time(node * root, char season[]);	//recursive call to display by the seasonal match
		int height(node * root) const;	//recursive call to evaluate the height of the tree
};
