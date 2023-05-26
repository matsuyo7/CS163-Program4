#include "tree.h"
using namespace std;

//Prototypes
int menu();
void get_travel(client & your_trip, table & my_tree);


int main()
{
	//Variables
	table my_tree;
	travel my_trip;
	client your_trip;
	int option {0};

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
                        //remove_match(match_remove, my_table);
                }
		else if (option == 4)
                {
                        //retrieve_match(match_retrieve, my_table, to_retrieve);
                }
		else if (option == 5)
                {
                        //display_all_time(match_time, my_table);
                }
		else if (option == 6)
		{

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
