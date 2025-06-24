
#include "../Include/Menu.h"
namespace fs = std::filesystem;

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

void Admin::display()
{

	cout << endl << endl;
	std::filesystem::path path;

	if (cinema == 1)
		path = "cinemaCity\\Movie";
	else if (cinema == 2)
		path = "cinemaMax\\Movie";

	for (const auto& e : fs::directory_iterator(path))
	{
		if (e.is_regular_file())
			std::cout << e.path().filename() << std::endl;
	}

}
void Admin::addShow()
{
	display();
	cout << "Which movie you want to select" << endl;
	string name;
	cin >> name;
	cout << "Enter show date" << endl;
	string date;
	cin >> date;
	projectionDate = date;
	filmTittle = name;
	cout << "Choose seat type, you can choose from: Silver, Gold and Platinum" << endl;
	string type;
	cin >> type;

	if (type == "Silver" || type == "Gold" || type == "Platinum")
		typeOfSeat = type;

	string current;
	if (cinema == 1)
		current = "cinemaCity\\Show\\";
	else if (cinema == 2)
		current = "cinemaMax\\Show\\";

	ofstream fileShow(current + name + ".txt");
	filmTittle = name;
	projectionDate = date;
	typeOfSeat = type;

	fileShow << filmTittle << endl;
	fileShow << projectionDate << endl;
	fileShow << typeOfSeat << endl;

	fileShow.close();
}
void Admin::deletefilm()
{
		display();
		string movie;
		cout << "Enter movie: ";
		cin >> movie;
		switch (cinema) 
		{
		case 1: 
		{
			string filename = "cinemaCity\\Movie\\" + movie + ".txt";
			remove(filename.c_str());
			cout << "DONE";
			break;
		}
		case 2:
		{
			string filename = "cinemaMax\\Movie\\" + movie + ".txt";
			remove(filename.c_str());
			cout << "DONE";
			break;
		}

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
		makeFilm.open("cinemaCity\\Movie\\" + movieInfo.title + ".txt");
	}
	else if (cinema == 2)
	{
		makeFilm.open("cinemaMax\\Movie\\" + movieInfo.title + ".txt");
	}
	makeFilm << movieInfo.title << endl;
	makeFilm << movieInfo.language << endl;
	makeFilm << movieInfo.genre << endl;
	makeFilm << movieInfo.releaseDate << endl;

	makeFilm.close();
}

void Admin::createOrDeleteMovie()
{
	cout << "Choose what you wnat to do" << endl;
	cout << "1 for adding a new movie" << endl;
	cout << "2 for deleting an existing movie" << endl;
	cout << "3 for adding a show" << endl;
	cout << "4 for deleting a show" << endl;
	cout << "5 for updating a show" << endl;
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
		deletefilm();
		break;
	case 3:
		clearscreen();
		cout << "You have chosen to add a show!";
		addShow();
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