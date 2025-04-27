#include "menu.h"


void Admin::adminMenu()
{
    cout << "You have selected the admin menu!";
}
void Customer::customerMenu()
{
    cout << "You have selected the customer menu!";
}

void menuChoice()
{
    cout << "Select menu" << endl << "1 for custumers" << endl << "2 for admin" << endl;
    int menuChoose;
    cin >> menuChoose;

    Admin* aptr = new Admin;
    Customer* cptr = new Customer;

    switch(menuChoose)
    {
        case 1:
        cptr->customerMenu();
        break;
        case 2:
        aptr->adminMenu();
        break;
        default:
        cout << "Incorrect input!";
        break;
    }
    delete aptr;
    delete cptr;
}

