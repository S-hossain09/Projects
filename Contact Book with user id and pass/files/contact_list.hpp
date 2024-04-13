// C++ Program to test presence of file
#include <iostream>
#include <string>
#include <sys/stat.h> // For using stat() function to check file existence
#include <map>
#include <sstream>
#include "login_out.hpp"

#ifndef CONTACT_LIST
#define CONTACT_LIST

using namespace std;


#define CONTACT_STORING_PATH "/mnt/d/Code/projects/Made with CPP/Arrays & Hashmaps/Contact Book with user id and pass/User_Details/contact_lists/"

void phone_book_options();
void logging_out();
void main_menu_back_options();

char password_file_exist_or_not(string name_of_file)
{
    string filepath = PASSWORD_STORE_PATH + name_of_file + ".txt";
    struct stat sb;
    /*
        variable sb of type struct stat.
        It is used to store the information
        about the file whose presence is being tested.
    */

    /*
        check if sb is a dir or not .
        by this line (sb.st_mode & S_IFDIR)
    */

    if (stat(filepath.c_str(), &sb) == 0 && !(sb.st_mode & S_IFDIR)) // Check if file exists and is not a directory
    {
        return 'y'; // File exists
    }
    else
    {
        return 'n'; // File does not exist
    }
}

// Function to check if a file is empty
bool isFileEmpty(const string &filename)
{
    ifstream file(filename);
    return file.peek() == ifstream::traits_type::eof();
    /*
    if the .txt file is empty it indicates that first line and last
    line are equal which so it returns true.
    */
}

void adding_contacts(const string &name_of_file, map<string, string> &map_contact_list)
{
    system("clear");
    /*
        for windows : try this system("cls") if system("clear") shows any errors
    */

    string contact_name;
    string contact_number;

    cout << endl;
    cout << "Enter the name of the contact: " << endl;
    cin >> contact_name;

    cout << "Enter the number of the contact: " << endl;
    cin >> contact_number;


    map_contact_list[contact_name] = contact_number;

    ofstream writing_contacts_in_list;
    writing_contacts_in_list.open(name_of_file);

    // checking if file opened successfuly to write
    if (!writing_contacts_in_list)
    {
        cout << "Error:\tUnable to open file for saving contacts" << endl;
        return;
    }

    for (auto it : map_contact_list)
    {
        writing_contacts_in_list << it.first << "\t\t\t" << it.second << endl;
    }

    writing_contacts_in_list.close();
    // closing what was opened to write previously.

    cout << endl;
    cout << "contacts updated successfully" << endl;

    main_menu_back_options();
}

void updating_contact(const string &name_of_file)
{
    map<string, string> map_conctact_list;

    if (isFileEmpty(name_of_file))
    {
        adding_contacts(name_of_file, map_conctact_list);
    }

    // if there is already contacts in the file then
    else if (!isFileEmpty(name_of_file))
    {
        ifstream input_from_file(name_of_file);

        // Check if the file is opened successfully
        if (!input_from_file.is_open())
        {
            cout << "Error:\tUnable to open file for scanning" << endl;
            return;
        }

        /*
            this will read each line of the contacts file until it reaches 
            the end of the file .
        */
        string line;
        while (getline(input_from_file, line))
        {
            stringstream ss(line);

            string name, number;
            ss >> name >> number;

            map_conctact_list[name] = number;
        }

        adding_contacts(name_of_file, map_conctact_list);
    }
}

void contacts_file()
{
    char if_file_exists = password_file_exist_or_not(username);

    if (if_file_exists == 'y')
    {
        updating_contact(CONTACT_STORING_PATH + username + ".txt");
    }

    else if (if_file_exists == 'n')
    {
        cout << endl;
        cout << "The file does not exist!!!" << endl;
    }
}

void if_user_updates_contact()
{
    contacts_file();
}

#endif // CONTACT_LIST