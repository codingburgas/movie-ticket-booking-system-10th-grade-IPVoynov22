#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Admin
{
    public:
    void adminMenu();
    void adminLogIn();
    void createOrDeleteMovie();
};
class Customer
{
    public:
    void customerMenu();
    void customerLogin();
};
    

void menuChoice();
void chooseCinema();
