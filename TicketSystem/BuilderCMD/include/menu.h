#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdio>

using namespace std;

extern const double silverTicket;
extern const double goldTicket;
extern const double platinumTicket;

class Admin
{   
    int seats[9][9] = { 0 };
    int row, col;
    string showName;
    public:
    void adminMenu();
    void adminLogIn();
    void createOrDeleteMovie();
    void addFilm();
    void deletefilm();
    void addShow();
    void deleteShow();
    void updateShow();
    void chooseCinema();
    void display();
    void displayShow();
    void loadSeats();
    void saveSeats();
    void bookSeat();
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

static string tierFromRow(int r);
static double priceFromRow(int r);