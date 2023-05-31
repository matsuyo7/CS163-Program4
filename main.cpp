#include "tree.h"
using namespace std;

//Prototypes
int menu();
void get_travel(client & your_trip, table & my_tree);
void remove_match(char match_remove[], table & my_tree);
void retrieve_match(char match_retrieve[], table & my_tree, travel & to_retrieve);
void display_all_time(char match_time[], table & my_tree);

int main()
{
	//Variables
	table my_tree;
	travel my_trip, to_retrieve;
	client your_trip;
	int option {0};
	char match_remove[SIZE];
	char match_retrieve[SIZE];
	char match_time[SIZE];

	do
        {
                option = menu();
                if (option == 1)
                {
                        get_travel(your_trip, my_tree);
                }
		else if (option == 2)
                {
                        my_tree.display_all();
                }
		else if (option == 3)
                {
                        remove_match(match_remove, my_tree);
                }
		else if (option == 4)
                {
                        retrieve_match(match_retrieve, my_tree, to_retrieve);
                }
		else if (option == 5)
                {
                        display_all_time(match_time, my_tree);
                }
		else if (option == 6)
		{
			cout << "\nHeight of tree: " << my_tree.height() << endl;
		}
        } while (option != 7);
        return 0;
}

//Functions
//Menu for the user to choose an option
int menu()
{
        int option = 0;
        cout << "\n***TRAVEL LIST***"
                << "\n1. Add a place to visit"
                << "\n2. Display all"
                << "\n3. Remove a location by name"
                << "\n4. Retrieve a location by name"
                << "\n5. Display all by season(s)"
		<< "\n6. Height of the tree"
                << "\n7. Quit";
        do
        {
                cout << "\nPick an option: ";
                cin >> option;
                cin.ignore(100, '\n');
                if (option < 1 || option > 7)
                        cout << "\nTry again" << endl;
        } while (option < 1 || option > 7);
        return option;
}
//Prompt the user for the travel information
void get_travel(client & your_trip, table & my_tree)
{
        cout << "\nName of the location: ";
        cin.get(your_trip.c_name, SIZE, '\n');
        cin.ignore(100, '\n');
        cout << "\nState and/or country (state, country): ";
        cin.get(your_trip.c_country, SIZE, '\n');
        cin.ignore(100, '\n');
        cout << "\nBest thing to do there: ";
        cin.get(your_trip.c_attract, SIZE, '\n');
        cin.ignore(100, '\n');
        cout << "\nBest time/season to go there: ";
        cin.get(your_trip.c_time, SIZE, '\n');
        cin.ignore(100, '\n');
        cout << "\nHow to travel to there: ";
        cin.get(your_trip.c_transport, SIZE, '\n');
        cin.ignore(100, '\n');
        cout << "\nImportant notes: ";
        cin.get(your_trip.c_notes, SIZE, '\n');
        cin.ignore(100, '\n');
        if (!my_tree.insert(your_trip))
                cerr << "\nCouldn't insert" << endl;
}
//Remove by a matching location name
void remove_match(char match_remove[], table & my_tree)
{
        cout << "\nWhat location do you want to remove: ";
        cin.get(match_remove, SIZE, '\n');
        cin.ignore(100, '\n');
        if (!my_tree.remove_location(match_remove))
                cout << "\nCouldn't remove" << endl;
        else
                cout << "\nRemoved" << endl;
}
//Retrieve a particular match by name but not displaying it
void retrieve_match(char match_retrieve[], table & my_tree, travel & to_retrieve)
{
        cout << "\nWhat location do you want to retrieve: ";
        cin.get(match_retrieve, SIZE, '\n');
        cin.ignore(100, '\n');
        if (!my_tree.retrieve_match_name(match_retrieve, to_retrieve))
                cerr << "\nCouldn't retrieve" << endl;
        else
                to_retrieve.display();
}
//Display all locations with good seasonal times to go
void display_all_time(char match_time[], table & my_tree)
{
        cout << "\nWhat season(s) to look for: ";
        cin.get(match_time, SIZE, '\n');
        cin.ignore(100, '\n');
        if (!my_tree.display_match_time(match_time))
                cout << "\nCouldn't display" << endl;
}

