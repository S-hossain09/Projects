#include <iostream>
#include "contact_list.hpp"

#ifndef SHOWING_CONTACTS
#define SHOWING_CONTACTS

using namespace std;

void phone_book_options();
void logging_out();
void main_menu_back_options();
void if_user_updates_contact();

void showing_contacts()
{
    string filename = CONTACT_STORING_PATH + username + ".txt";
    ifstream file(filename); // Open file

    if (!file.is_open())
    {
        system("clear");

        cout << endl;
        cout << "You have not added any contacts in your phone book" << endl << endl << endl;

        char adding_contacts_options;
        cout << "Do you want to add any contacts ?" << endl;
        cout << "(select y/Y or n/N)" << endl;
        cout << "Enter : ";

        cin >> adding_contacts_options;
        cout << endl << endl;

        if(adding_contacts_options == 'y' || adding_contacts_options == 'Y')
        {
            if_user_updates_contact();
        }

        else
        {
            main_menu_back_options();
            cout << endl;
        }
    }

    else
    {
        cout << endl;
        cout << "Showing all your contacts:" << endl;

        cout << endl
             << endl;
        cout << "Name"
             << "\t\t\t"
             << "Number" << endl;

        cout << "___________________________________" << endl;

        string line;
        while (getline(file, line))
        {
            stringstream ss(line);

            string name, number;
            ss >> name >> number;

            cout << name << "\t\t\t" << number << endl;
        }
        cout << endl
             << endl;
    }

    file.close();
}

#endif // SHOWING_CONTACTS