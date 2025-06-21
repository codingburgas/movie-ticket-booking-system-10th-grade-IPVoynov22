#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdio>

using namespace std;

class Admin
{   
    public:
    void adminMenu();
    void adminLogIn();
    void createOrDeleteMovie();
    void addFilm();
    void deletefilm();
    void chooseCinema();
    void display();
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
