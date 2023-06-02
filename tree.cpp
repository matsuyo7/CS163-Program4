#include "tree.h"
using namespace std;

//Molina Nhoung, CS163, 5/23/23, Program 4
//The purpose of this file is to implement the wrapper and recursive functions for the
//bst class. This allows other programmers to examine how the functions would work
//and how to use this to interact with the client. The wrapper function allows the before and after
//recursion so fully implement the recursion aspects.

//constructor that will initialize the data members
table::table()
{
	root = nullptr;
}
//destructor to deallocate the data members
table::~table()
{
	remove_all(root);
}
//recursive call to deallocate memory
int table::remove_all(node * & root)
{
	if (!root)
		return 0;
	remove_all(root->left);
	remove_all(root->right);
	if (root)
		delete root;
	root = nullptr;
	return 1;
}
//add a travel item that's passed in as an argument and add it to the BST
int table::insert(const client & to_add)
{
	if (to_add.c_name == nullptr || to_add.c_country == nullptr || to_add.c_attract == nullptr || to_add.c_time == nullptr
        || to_add.c_transport == nullptr || to_add.c_notes == nullptr)
		return 0;
	return insert(root, to_add);
}
//recursive call for inserting
int table::insert(node * & root, const client & to_add)
{
	if (!root)	//empty tree or end of traversal
	{
		root = new node;
		root->trip.create(to_add);
		root->left = root->right = nullptr;
		return 1;
	}
	int same = root->trip.compare(to_add.c_name);
	if (same == 1)	//less than data go to the left
		insert(root->left, to_add);
	else if (same == 2)	//equal to or more than go to the right
		insert(root->right, to_add);
	return 1;
}
//display all travel information
int table::display_all() const
{
	if (!root)	//emtpy tree
		return 0;
	return display_all(root);
}
//recursive call for displaying all
int table::display_all(node * root) const
{
	if (!root)	//empty tree
		return 0;
	display_all(root->left);
	root->trip.display();
	display_all(root->right);
	return 1;
}
	
//remove by the locatin name
int table::remove_location(char location[])
{
	if (!root)	//emptry tree
		return 0;
	return remove_location(root, location);
}
//recursive call to remove an item
int table::remove_location(node * & root, char location[])
{
	if (!root)	//stop traversing
		return 0;
	node * hold = nullptr;
	if (!root->trip.find(location))	//traverse until found a match
	{
		return remove_location(root->left, location) + remove_location(root->right, location);
	}
	if (!root->left && !root->right)	//leaf
	{
		delete root;
		root = nullptr;
	}
	else if (root->left && !root->right)	//left child isn't null
	{
		hold = root->left;
		delete root;
		root = hold;
	}
	else if (!root->left && root->right)	//right child isn't null
	{
		hold = root->right;
		delete root;
		root = hold;
	}
	else
	{
		node * current = root->right;
		node * previous = current;
		if (!current->left)
		{
			hold = current->right;
			root->trip.copy_name(current->trip);
			delete current;
			root->right = hold;
		}
		else
		{
			while (current->left)
			{
				previous = current;
				current = current->left;
			}
			root->trip.copy_name(current->trip);
			hold = current->right;
			delete current;
			previous->left = hold;
		}
	}
	return 1;
}
//retrieve the information from the particular location name match
int table::retrieve_match_name(char match[], travel & find)
{
	if (!root)
		return 0;
	return retrieve_match_name(root, match, find);
}
//recursive call to retrieve from the list
int table::retrieve_match_name(node * root, char match[], travel & find)
{
	if (!root)
		return 0;
	if (root->trip.retrieve(match, find))
		return 1;
	return retrieve_match_name(root->left, match, find) + retrieve_match_name(root->right, match, find);
}
//display by the seasonal match
int table::display_match_time(char season[])
{
	if (!root)
		return 0;
	return display_match_time(root, season);
}
//recursive call to display by the seasonal match
int table::display_match_time(node * root, char season[])
{
	if (!root)
		return 0;
	if (root->trip.find(season))
	{
		root->trip.display();
		return 1;
	}
	return display_match_time(root->left, season) + display_match_time(root->right, season);
}
//evaluate the height of the tree
int table::height() const
{
	if (!root)
		return 0;
	return height(root);
}
//recursive call to evaluate the height of the tree
int table::height(node * root) const
{
	if (!root)
		return 0;
	return max(height(root->left), height(root->right)) + 1;
}
