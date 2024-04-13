#include "showing_contacts.hpp"

#ifndef PHONE_BOOK_OPTIONS
#define PHONE_BOOK_OPTIONS

using namespace std;

void phone_book_options()
{
    int options;

    cout << endl;
    cout << "Choose options from below: " << endl;

    cout << "1.  Add any contact" << endl;
    cout << "2.  Show all my contacts" << endl;
    cout << "3.  Log out" << endl;
    cout << "Enter : ";

    cin >> options;
    

    if (options == 1) // Option to add a contact
    {
        if_user_updates_contact(); // Call function to add contact
    }
    else if (options == 2) // Option to show contacts
    {
        showing_contacts(); // Call function to show contacts
    }

    else // Option to log out
    {
        logging_out(); // Call function to log out
    }
}

void main_menu_back_options()
{
    cout << endl;
    char main_menu_options;
    cout << "Do you want to go to the main menu:" << endl;
    cout << "(select y/Y or n/N)" << endl;
    cout << "Enter : ";

    cin >> main_menu_options;

    if(main_menu_options == 'y' || main_menu_options == 'Y')
    {
        system("clear");
        phone_book_options();
    }

    else if(main_menu_options == 'n' || main_menu_options == 'N')
    {
        cout << endl;
        logging_out();
    }
}

#endif // PHONE_BOOK_OPTIONS

