#pragma once

#include "functions.h"

int manageObject(int choice)
{
    std::string object = "";
    if (choice == 1)
    {
        object = "User";
    }
    else if (choice == 2)
    {
        object = "Centre";
    }
    else if (choice == 3)
    {
        object = "Subject";
    }
    else if (choice == 4)
    {
        object = "Tutor";
    }
    system("cls");
    // view user
    std::cout << "1 - View All " << object << "s" << std::endl;
    // search user
    std::cout << "2 - Search " << object << std::endl;
    // add user
    std::cout << "3 - Add " << object << std::endl;
    // edit user
    std::cout << "4 - Edit " << object << std::endl;
    // delete user
    std::cout << "5 - Delete " << object << std::endl;
    if (choice == 4)
    {
        // terminate tutor
        std::cout << "6 - Terminate Tutor" << std::endl;
        // exit
        std::cout << "7 - Back" << std::endl;
    }
    else
    {
        // exit
        std::cout << "6 - Back" << std::endl;
    }

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    if (choice == 4)
    {
        while (!std::cin.good() || input < 1 || input > 7)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> input;
        }
    }
    else
    {
        while (!std::cin.good() || input < 1 || input > 6)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> input;
        }
    }
    return input;
}

int viewTutorSorted()
{
    system("cls");
    std::cout << "1 - View Tutors sorted by ID" << std::endl;
    std::cout << "2 - View Tutors sorted by Hourly Pay Rate" << std::endl;
    std::cout << "3 - View Tutors sorted by Rating" << std::endl;
    std::cout << "4 - Back" << std::endl;

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    while (!std::cin.good() || input < 1 || input > 4)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> input;
    }
    return input;
}

int searchTutorDashboard(int userType)
{
    system("cls");
    std::cout << "1 - Search Tutor by ID" << std::endl;
    std::cout << "2 - Filter Tutors by Rating" << std::endl;
    std::cout << "3 - Filter Tutors by Subject ID" << std::endl;
    if (userType == 0)
    {
        std::cout << "4 - Filter Tutors by Centre ID" << std::endl;
        std::cout << "5 - Back" << std::endl;
    }
    else
    {
        std::cout << "4 - Back" << std::endl;
    }

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    if (userType == 0)
    {
        while (!std::cin.good() || input < 1 || input > 5)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> input;
        }
    }
    else
    {
        while (!std::cin.good() || input < 1 || input > 4)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> input;
        }
    }
    return input;
}

int ratingValidation()
{
    int rating;
    std::cout << "Enter your rating: ";
    std::cin >> rating;
    while (std::cin.fail() || rating < 1 || rating > 5)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your rating: ";
        std::cin >> rating;
    }
    return rating;
}

int subjectValidation()
{
    int subjectId;
    std::cout << "Enter your subject ID: ";
    std::cin >> subjectId;
    while (!std::cin.good() || linearSearch(subjectHead, subjectTail, subjectId) == NULL)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your subject ID: ";
        std::cin >> subjectId;
    }
    return subjectId;
}

int centreValidation()
{
    int centreId;
    std::cout << "Enter your centre ID: ";
    std::cin >> centreId;
    while (!std::cin.good() || linearSearch(centreHead, centreTail, centreId) == NULL)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your centre ID: ";
        std::cin >> centreId;
    }
    return centreId;
}
// ---------------------------------------------- Dashboards ----------------------------------------------
void displayHrMenu()
{
    int choice, tutorViewChoice, searchTutorChoice;
    std::cout << "1 - Manage Users" << std::endl;
    std::cout << "2 - Manage Centres" << std::endl;
    std::cout << "3 - Manage Subjects" << std::endl;
    std::cout << "4 - Manage Tutors" << std::endl;
    std::cout << "5 - Add Ratings" << std::endl;
    std::cout << "6 - View Tutor Archive" << std::endl;
    std::cout << "7 - Exit Program" << std::endl;

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    while (!std::cin.good() || input < 1 || input > 7)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> input;
    }

    switch (input)
    {
        // ---------------------------------------------------------------------------------- Manage Users ----------------------------------------------------------------------------------
    case 1:
        choice = manageObject(1);
        // view all users
        if (choice == 1)
        {
            std::cout << std::endl;
            displayUserList();
            displayHrMenu();
        }
        // search user
        else if (choice == 2)
        {
            searchUser();
            displayHrMenu();
        }
        // add user
        else if (choice == 3)
        {
            addUser();
            displayHrMenu();
        }
        // edit user
        else if (choice == 4)
        {
            updateUser();
            displayHrMenu();
        }
        // delete user
        else if (choice == 5)
        {
            deleteUser();
            displayHrMenu();
        }
        else if (choice == 6)
        {
            system("cls");
            displayHrMenu();
        }
        // ---------------------------------------------------------------------------------- Manage Centres ----------------------------------------------------------------------------------
    case 2:
        choice = manageObject(2);
        // view all centres
        if (choice == 1)
        {
            std::cout << std::endl;
            displayCentreList();
            displayHrMenu();
        }
        // search centre
        else if (choice == 2)
        {
            searchCentre();
            displayHrMenu();
        }
        // add Centre
        else if (choice == 3)
        {
            addCentre();
            displayHrMenu();
        }
        // edit centre
        else if (choice == 4)
        {
            updateCentre();
            displayHrMenu();
        }
        // delete centre
        else if (choice == 5)
        {
            deleteCentre();
            displayHrMenu();
        }
        else if (choice == 6)
        {
            system("cls");
            displayHrMenu();
        }
    case 3:
        // ---------------------------------------------------------------------------------- Manage Subjects ----------------------------------------------------------------------------------
        choice = manageObject(3);
        // view all subjects
        if (choice == 1)
        {
            std::cout << std::endl;
            displaySubjectList();
            displayHrMenu();
        }
        // search subject
        else if (choice == 2)
        {
            searchSubject();
            displayHrMenu();
        }
        // add Subject
        else if (choice == 3)
        {
            addSubject();
            displayHrMenu();
        }
        // edit subject
        else if (choice == 4)
        {
            updateSubject();
            displayHrMenu();
        }
        // delete subject
        else if (choice == 5)
        {
            deleteSubject();
            displayHrMenu();
        }
        else if (choice == 6)
        {
            system("cls");
            displayHrMenu();
        }
    case 4:
        // ---------------------------------------------------------------------------------- Manage Tutors ----------------------------------------------------------------------------------
        choice = manageObject(4);
        // view all tutors
        if (choice == 1)
        {
            tutorViewChoice = viewTutorSorted();
            system("cls");
            // view tutors sorted by ID
            if (tutorViewChoice == 1)
            {
                filterTutors(-1, -2, -2, tutorHead);
                displayHrMenu();
            }
            // view tutors sorted by hourly pay rate
            else if (tutorViewChoice == 2)
            {
                duplicateTutorLinkedList(tutorHPRHead, tutorHPRTail, tutorHead);
                tutorHPRHead = mergeSortHPR(tutorHPRHead);
                filterTutors(-1, -2, -2, tutorHPRHead);
                displayHrMenu();
            }
            // view tutors sorted by rating
            else if (tutorViewChoice == 3)
            {
                duplicateTutorLinkedList(tutorRatingHead, tutorRatingTail, tutorHead);
                tutorRatingHead = mergeSortRatings(tutorRatingHead);
                filterTutors(-1, -2, -2, tutorRatingHead);
                displayHrMenu();
            }
            else
            {
                displayHrMenu();
            }
        }
        // search tutor
        else if (choice == 2)
        {
            searchTutorChoice = searchTutorDashboard(0);
            system("cls");
            // search tutor by ID
            if (searchTutorChoice == 1)
            {
                searchTutorById(-1);
                displayHrMenu();
            }
            // filter by Rating
            else if (searchTutorChoice == 2)
            {
                int ratings = ratingValidation();
                filterTutors(-2, -2, ratings, tutorHead);
                displayHrMenu();
            }
            // filter by Subject ID
            else if (searchTutorChoice == 3)
            {
                int subjectId = subjectValidation();
                filterTutors(-2, subjectId, -2, tutorHead);
                displayHrMenu();
            }
            // filter by Centre ID
            else if (searchTutorChoice == 4)
            {
                int centreId = centreValidation();
                filterTutors(centreId, -2, -2, tutorHead);
                displayHrMenu();
            }
            else
            {
                displayHrMenu();
            }
        }
        // add Tutor
        else if (choice == 3)
        {
            addTutor(-1);
            displayHrMenu();
        }
        // edit tutor
        else if (choice == 4)
        {
            updateTutor(-1);
            displayHrMenu();
        }
        // delete tutor
        else if (choice == 5)
        {
            deleteTutor();
            displayHrMenu();
        }
        else if (choice == 6)
        {
            terminateTutor(-1);
            displayHrMenu();
        }
        else if (choice == 7)
        {
            system("cls");
            displayHrMenu();
        }
    case 5:
        // ---------------------------------------------------------------------------------- Add Ratings ----------------------------------------------------------------------------------
        addRating(-1);
        displayHrMenu();
    case 6:
        displayArchiveList();
        displayHrMenu();
    case 7:
        std::cout << "Exiting program..." << std::endl;
        exit(0);
        break;
        return;
    }
}

void displayAdminMenu(User *login)
{
    int choice, tutorViewChoice, searchTutorChoice;
    Centre *centre = centreLinearSearch(login->id, centreHead);
    std::cout << "1 - Manage Tutors" << std::endl;
    std::cout << "2 - View Centre Details" << std::endl;
    std::cout << "3 - View All Subjects" << std::endl;
    std::cout << "4 - Add Ratings" << std::endl;
    std::cout << "5 - View Tutor Archive" << std::endl;
    std::cout << "6 - Exit Program" << std::endl;

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

    switch (input)
    {
    // ---------------------------------------------------------------------------------- Manage Tutors ----------------------------------------------------------------------------------
    case 1:
        choice = manageObject(4);
        // view all tutors
        if (choice == 1)
        {
            tutorViewChoice = viewTutorSorted();
            system("cls");
            // view tutors sorted by ID
            if (tutorViewChoice == 1)
            {
                filterTutors(centre->id, -2, -2, tutorHead);
                displayAdminMenu(login);
            }
            // view tutors sorted by hourly pay rate
            else if (tutorViewChoice == 2)
            {
                duplicateTutorLinkedList(tutorHPRHead, tutorHPRTail, tutorHead);
                tutorHPRHead = mergeSortHPR(tutorHPRHead);
                filterTutors(centre->id, -2, -2, tutorHPRHead);
                displayAdminMenu(login);
            }
            // view tutors sorted by rating
            else if (tutorViewChoice == 3)
            {
                duplicateTutorLinkedList(tutorRatingHead, tutorRatingTail, tutorHead);
                tutorRatingHead = mergeSortRatings(tutorRatingHead);
                filterTutors(centre->id, -2, -2, tutorRatingHead);
                displayAdminMenu(login);
            }
            else
            {
                displayAdminMenu(login);
            }
        }
        // search tutor
        else if (choice == 2)
        {
            searchTutorChoice = searchTutorDashboard(1);
            system("cls");
            // search tutor by ID
            if (searchTutorChoice == 1)
            {
                searchTutorById(centre->id);
                displayAdminMenu(login);
            }
            // filter by Rating
            else if (searchTutorChoice == 2)
            {
                int ratings = ratingValidation();
                filterTutors(centre->id, -2, ratings, tutorHead);
                displayAdminMenu(login);
            }
            // filter by Subject ID
            else if (searchTutorChoice == 3)
            {
                int subjectId = subjectValidation();
                filterTutors(centre->id, subjectId, -2, tutorHead);
                displayAdminMenu(login);
            }
            else
            {
                displayAdminMenu(login);
            }
        }
        // add Tutor
        else if (choice == 3)
        {
            addTutor(centre->id);
            displayAdminMenu(login);
        }
        // edit tutor
        else if (choice == 4)
        {
            updateTutor(centre->id);
            displayAdminMenu(login);
        }
        // delete tutor
        else if (choice == 5)
        {
            system("cls");
            std::cout << "The delete function is not accessible by Admins. Please contact HR for support." << std::endl
                      << std::endl;
            displayAdminMenu(login);
        }
        else if (choice == 6)
        {
            terminateTutor(centre->id);
            displayAdminMenu(login);
        }
        else if (choice == 7)
        {
            system("cls");
            displayAdminMenu(login);
        }
    case 2:
        displayCentre(centre);
        displayAdminMenu(login);
    case 3:
        std::cout << std::endl;
        displaySubjectList();
        displayAdminMenu(login);
    case 4:
        addRating(centre->id);
        displayAdminMenu(login);
    case 5:
        displayArchiveList();
        displayHrMenu();
    case 6:
        std::cout << "Exiting program..." << std::endl;
        exit(0);
        break;
        return;
    }
}

void displayTutorMenu(User *login)
{
    int tutorId = std::stoi(login->username);
    Tutor *tutor = linearSearch(tutorHead, tutorTail, tutorId);
    Centre *centre = linearSearch(centreHead, centreTail, tutor->centreId);
    Subject *subject = linearSearch(subjectHead, subjectTail, tutor->subjectId);

    std::cout << "1 - View Centre Details" << std::endl;
    std::cout << "2 - View Subject Details" << std::endl;
    std::cout << "3 - View Tutor Details" << std::endl;
    std::cout << "4 - Exit Program" << std::endl;

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    while (!std::cin.good() || input < 1 || input > 4)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> input;
    }

    switch (input)
    {
    case 1:
        displayCentre(centre);
        displayTutorMenu(login);
    case 2:
        displaySubject(subject);
        displayTutorMenu(login);
    case 3:
        displayTutor(tutor);
        displayTutorMenu(login);
    case 4:
        std::cout << "Exiting program..." << std::endl;
        exit(0);
        break;
        return;
    }
}
