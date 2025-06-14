
#include "../Include/Menu.h"

void clearscreen()
{
	system("cls");
}

void Admin::adminLogIn()
{
	string userName;
	string passWord;

	string adminUsername;
	string adminPassword;

	ifstream file("Users\\adminData.txt");

	getline(file, adminUsername);
	getline(file, adminPassword);

	file.close();
	
	cout << "                               You have chosen admin menu!" << endl;
	cout << "You have to log in to use admin menu!" << endl << "Username: ";
	cin >> userName;
	if (userName == adminUsername)
	{
		cout << "Password: ";
		cin >> passWord;
		if (passWord == adminPassword)
		{
			clearscreen();
			cout << "                       You have loged in successfully!" << endl;
		}
		else
		{
			cout << "Incorrect password!";
			exit(0);
		}
	}
	else
	{
		cout << "Incorrect username!";
		exit(0);
	}
}

void Admin::addFilm()
{
	ofstream makeFilm;
	MovieInfo movieInfo;
	cout << "Enter movie title: ";
	cin >> movieInfo.title;
	cout <<  endl << "Enter movie language: ";
	cin >> movieInfo.language;
	cout << endl << "Enter movie genre: ";
	cin >> movieInfo.genre;
	cout << endl << "Enter movie releaseDate: ";
	cin >> movieInfo.releaseDate;
	if (cinema == 1)
	{
		makeFilm.open("cinemaMax\\Movie\\Movie" + movieInfo.title + ".txt");
	}
	else if (cinema == 2)
	{
		makeFilm.open("cinemaCity\\Movie\\Movie" + movieInfo.title + ".txt");
	}
	makeFilm << movieInfo.title << endl;
	makeFilm << movieInfo.language << endl;
	makeFilm << movieInfo.genre << endl;
	makeFilm << movieInfo.releaseDate << endl;
}

void Admin::createOrDeleteMovie()
{
	cout << "Choose what you wnat to do" << endl << "1 for adding a new movie" << endl << "2 for deleting an existing movie" << endl;
	int inAdminMenuChoice;
	cin >> inAdminMenuChoice;
	switch (inAdminMenuChoice)
	{
	case 1:
		clearscreen();
		cout << "You have chosen to add a film!" << endl;
		addFilm();
		break;
	case 2:
		clearscreen();
		cout << "You have chosen to delete an existing film!";
		break;
	default:
		clearscreen();
		cout << "Incorrect input";
		break;
	}
}
void Admin::adminMenu()
{
	clearscreen();
	adminLogIn();
	chooseCinema();
	createOrDeleteMovie();
}

void Customer::customerMenu()
{
	clearscreen();
	customerLogin();
}

void Admin::chooseCinema()
{
	clearscreen();
	cout << "Choose in which cinema you want to go" << endl << "1 for cinemaCity" << endl << "2 for cinemaMax" << endl;
	cin >> cinema;
	switch (cinema)
	{
	case 1: clearscreen();
		cout << "You have entered cinemaCity";
		break;
	case 2: clearscreen();
		cout << "You have entered cinemaMax";;
		break;
	default: clearscreen();
		cout << "Incorrect input";
	}
	cout << endl;
}



void menuChoice()
{
	Customer* customerPtr = new Customer;
	Admin* adminPtr = new Admin;

	cout << "Select menu" << endl << "1 For customers" << endl << "2 For Admin" << endl;

	int menuChoose;
	cin >> menuChoose;

	switch (menuChoose)
	{
	case 1:
		customerPtr->customerMenu();

		break;
	case 2:
		adminPtr->adminMenu();

		break;
	default:
		clearscreen();
		cout << "Incorrect input!";

	}

	delete customerPtr;
	delete adminPtr;
}

void Customer::customerLogin()
{
	cout << "You have chosen customer menu!" << endl;
	cout << "1 for Register" << endl << "2 for Login" << endl;
	int registOrLog;
	cin >> registOrLog;

	string userRegister, passRegister;
	string userLogIn, passLogIn;

	switch (registOrLog)
	{
	case 1:
	{
		clearscreen();

		ifstream customer("Users\\Customer.txt");
		if (!customer.is_open())
		{
			cout << "You chose to register" << endl;
			cout << "Username:";
			cin >> userRegister;
			ofstream createFile("Users\\Customer.txt");
			createFile << userRegister << endl;
			cout << "Password:";
			cin >> passRegister;
			createFile << passRegister << endl;
			createFile.close();

		}
		else
		{
			customer.close();
		}
		break;
	}
	case 2:
		cout << "You chose to logIn" << endl;
		cout << "Username:";
		string userUsername;
		string userPassword;

		ifstream file("Users\\Customer.txt");

		getline(file, userUsername);
		getline(file, userPassword);

		cin >> userLogIn;
		if (userLogIn == userUsername)
		{
			cout << "Password:";
			cin >> passLogIn;
			if (passLogIn == userPassword)
			{
				cout << "You successfully logged in";
			}
		}
		
		break;
	}
}


