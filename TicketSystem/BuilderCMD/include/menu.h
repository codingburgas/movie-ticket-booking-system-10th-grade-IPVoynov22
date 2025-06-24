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
    void addShow();
    void deleteShow();
    void chooseCinema();
    void display();
    int cinema;
    string projectionDate;
    string filmTittle;
    string typeOfSeat;
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