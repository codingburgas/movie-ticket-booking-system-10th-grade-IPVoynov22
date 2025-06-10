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
    void addFilm();
    void chooseCinema();
    int cinema;
};
class Customer
{
    public:
    void customerMenu();
    void customerLogin();
};
struct MovieInfo
{
    string title, language, genre, releaseDate;
};

void menuChoice();