#pragma once
#include "includes.h"
#include "functions.h"

// create user class doubly linked list with unsignedInt: userId, string: username, string: password, unsignedInt: userType
class User
{
public:
    int id;
    std::string username;
    std::string password;
    unsigned int userType; // 0-HR, 1-Admin, 2- Tutor
    User *nextAddress = NULL;
    User *previousAddress = NULL;

    // constructor
    User(int id, std::string username, std::string password, unsigned int userType)
    {
        this->id = id;
        this->username = username;
        this->password = password;
        this->userType = userType;
        this->nextAddress = NULL;
        this->previousAddress = NULL;
    };

} * userHead, *userTail;

// print user list
void displayUserList()
{
    User *current = userHead;
    while (current != NULL)
    {
        std::cout << "User ID: " << current->id << std::endl;
        std::cout << "Username: " << current->username << std::endl;
        std::cout << "Password: " << current->password << std::endl;
        std::cout << "User Type: " << current->userType << std::endl
                  << std::endl;
        current = current->nextAddress;
    }
    delete current;
}

User *addUser()
{
    // prompt for input to fill in constructor
    std::string username;
    std::string password;
    unsigned int userType; // 0-HR, 1-Admin, 2- Tutor

    std::cout << "Please enter the following to create a new user account:" << std::endl;
    std::cout << "Enter Username: ";
    std::cin >> username;
    std::cout << "Enter Password: ";
    std::cin >> password;
    std::cout << "Enter User Type (0-HR, 1-Admin, 2- Tutor): ";
    // check for invalid input for userType
    std::cin >> userType;
    while (!std::cin.good() || userType < 0 || userType > 2)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter User Type (0-HR, 1-Admin, 2- Tutor): ";
        std::cin >> userType;
    }

    // create new user
    User *newUser = new User(getListSize(userHead), username, password, userType);
    std::cout << "User created successfully" << std::endl;
    return newUser;
}

void manageUsers()
{
    system("cls");
    // view user
    std::cout << "1 - View All Users" << std::endl;
    // search user
    std::cout << "2 - Search User" << std::endl;
    // add user
    std::cout << "3 - Add User" << std::endl;
    // edit user
    std::cout << "4 - Edit User" << std::endl;
    // delete user
    std::cout << "5 - Delete User" << std::endl;
    // exit
    std::cout << "6 - Back" << std::endl;

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    while (!std::cin.good() || input < 1 || input > 6)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> input;
    }

    if (input == 1)
    {
        displayUserList();
    }
    else if (input == 2)
    {
        // searchUser();
    }
    else if (input == 3)
    {

        User *newUser = addUser();
        insertAtEnd(newUser, userHead, userTail);
        displayUserList();
    }
    else if (input == 4)
    {
        // editUser();
    }
    else if (input == 5)
    {
        // deleteUser();
    }
    else if (input == 6)
    {
        system("cls");
        return;
    }
}
