
#include <iostream>
#include <fstream>

#define PASSWORD_STORE_PATH "/mnt/d/Code/projects/Made with CPP/Arrays & Hashmaps/Contact Book with user id and pass/User_Details/Usernames_&_Password/"

#ifndef LOGIN_OUT
#define LOGIN_OUT


using namespace std;


std::string username;
/*
    declaring this username globally so that 
    it is accessible in every file.
*/

using namespace std;

void phone_book_options();

// Function to check validity of username and password
bool checking_validity()
{
    string password;

    string confirmation_username, confirmation_password;

    cout << "Enter your Username : ";
    cin >> username;

    cout << "Enter password : ";
    cin >> password;

    ifstream reading_from_file(PASSWORD_STORE_PATH + username + ".txt");
    getline(reading_from_file, confirmation_username);
    getline(reading_from_file, confirmation_password);

    if (confirmation_username == username)
    {
        return true;
    }

    else
    {
        return false;
    }
}

// Function for logging in or creating an account
void logging_in()
{
    int options;

    cout << endl;
    cout << "Choose options below : " << endl;
    cout << endl;
    cout << "1.  Login" << endl;
    cout << "2.  Create an account" << endl;
    cout << "Enter : ";

    cin >> options;
    cout << endl;

    if (options == 1) // Logging in
    {
        bool status = checking_validity();

        if (status == true) // If username and password are valid
        {
            system("clear");

            cout << endl;
            cout << "Successfully Logged in" << endl;
            cout << endl;

            cout << "Welcome back " << username << endl;
            cout << endl;
        }

        else // If username and password are invalid
        {
            system("clear");

            cout << endl;
            cout << "Invalid User details!!!" << endl;
            cout << "Try again" << endl;

            logging_in(); // Retry login
        }
    }

    else if (options == 2) // Creating an account
    {
        string reg_username, reg_password;

        cout << "Enter an username : " << endl;
        cin >> reg_username;

        // Assigning registered username to global variable for later use
        username = reg_username;

        cout << "Enter password : " << endl;
        cin >> reg_password;

        ofstream writing_in_file;
        writing_in_file.open(PASSWORD_STORE_PATH + reg_username + ".txt");
        writing_in_file << reg_username << endl
                        << reg_password;

        system("clear");
        cout << endl;
        cout << "Account Created Successfully!!" << endl;
        writing_in_file.close();
    }
}

void logging_out()
{
    char options2;
    cout << "Do you really want to log out?" << endl;
    cout << "(Press y/Y for Yes , n/N for No)" << endl;
    cin >> options2;

    if (options2 == 'y' || options2 == 'Y')
    {
        cout << endl;
        cout << "Good Bye " << username << endl;
        cout << "Signing Out..." << endl;

        system("exit");
    }

    else if (options2 == 'n' || options2 == 'N')
    {
        cout << endl;
        cout << "Taking you back to main menu..." << endl;
        phone_book_options(); // Return to main menu
    }
}

#endif // LOGIN_OUT