# Personal Contact List

This is a protected Contact List. Here the user
will have an username and a password. The user will
need these to login and updates their contacts . 
The contacts will store into a different file in an 
ascending order . Every user here will have their 
different file for their contacts and password.

## Usage

To compile and run the project, follow these steps:

1. Navigate to the project directory in your terminal.

2. Compile the code using your preferred compiler (e.g., g++):
g++ -o main main.cpp

3. Run the compiled executable:
./main

## Warnings

There are a few things to be aware of when using this 
project:

- **Contacts Storing Path**: In contact_list.hpp there is a string literal named as CONTACT_STORING_PATH. Please modify it before running the code , assign it to the directory where the User Details's contact_list folder is.

- **Password Storing Path**: In login_out.hpp there is a string literal named as PASSWORD_STORE_PATH. Please modify it before running the code , assign it to the directory where the User Details's Usernames & Password folder is.

- **Clearing The terminal Command**: In this project it is used system("clear") for wsl , this might not work 
in windows . so try changing it to system("cls").


