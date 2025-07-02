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

void Admin::displayShow()
{
	cout << endl << endl;
	std::filesystem::path path;

	if (cinema == 1)
		path = "cinemaCity\\Show";
	else if (cinema == 2)
		path = "cinemaMax\\Show";

	for (const auto& e : fs::directory_iterator(path))
	{
		if (e.is_regular_file())
			std::cout << e.path().filename() << std::endl;
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
	Admin admin;
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

void Admin::deleteShow()
{
	display();
	string show;
	cout << "Enter show: ";
	cin >> show;
	switch (cinema)
		{
		case 1:
		{
			string filename = "cinemaCity\\Show\\" + show + ".txt";
			remove(filename.c_str());
			cout << "DONE";
			break;
		}
		case 2:
		{
			string filename = "cinemaMax\\Show\\" + show + ".txt";
			remove(filename.c_str());
			cout << "DONE";
			break;
		}
	}
}
void Admin::updateShow()
{
	displayShow();
	cout << "Choose which show you want to update" << endl;
	string showChoice;
	cin >> showChoice;

	string filePath;

	if (cinema == 1)
		filePath = "cinemaCity\\Show\\" + showChoice + ".txt";
	else if (cinema == 2)
		filePath = "cinemaMax\\Show\\" + showChoice + ".txt";

	ifstream inFile(filePath);

	if (!
		inFile.is_open())
	{
		cout << "Show not found!" << endl;
		return;
	}

	string currentTitle, currentDate, currentSeat;
	getline(inFile, currentTitle);
	getline(inFile, currentDate);
	getline(inFile, currentSeat);
	inFile.close();

	cout << "Current information:" << endl;
	cout << "Title: " << currentTitle << endl;
	cout << "Date: " << currentDate << endl;
	cout << "Seat Type: " << currentSeat << endl;

	cout << "\nEnter new title (or press Enter to keep it): ";
	cin.ignore(); 
	string newTitle;
	getline(cin, newTitle);
	if (newTitle.empty()) newTitle = currentTitle;

	cout << "Enter new date (or press Enter to keep it): ";
	string newDate;
	getline(cin, newDate);
	if (newDate.empty()) newDate = currentDate;

	cout << "Enter new seat type (Silver, Gold, Platinum) (or press Enter to keep it): ";
	string newSeat;
	getline(cin, newSeat);
	if (newSeat.empty()) newSeat = currentSeat;

	
	if (newTitle != currentTitle)
	{
		remove(filePath.c_str());
		if (cinema == 1)
			filePath = "cinemaCity\\Show\\" + newTitle + ".txt";
		else if (cinema == 2)
			filePath = "cinemaMax\\Show\\" + newTitle + ".txt";
	}

	ofstream outFile(filePath);
	outFile << newTitle << endl;
	outFile << newDate << endl;
	outFile << newSeat << endl;
	outFile.close();

	cout << "Show updated successfully!" << endl;
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
	cout << "6 for booking a seat" << endl;
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
	case 4:
		clearscreen();
		cout << "You have chosen to delete a show!";
		deleteShow();
		break;
	case 5:
		clearscreen();
		cout << "You have chosen to update a show!";
		updateShow();
		break;
	case 6:
		clearscreen();
		cout << "You have chosen to book a seat!";
		bookSeat();
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
	Admin admin;
	clearscreen();
	customerLogin();
	admin.chooseCinema();
	admin.bookSeat();
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

void Admin::loadSeats()
{
	string seatPath;
	if (cinema == 1)
		seatPath = "cinemaCity\\Seats\\" + showName + ".txt";
	else if (cinema == 2)
		seatPath = "cinemaMax\\Seats\\" + showName + ".txt";

	ifstream inFile(seatPath);
	if (!inFile.is_open())
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				seats[i][j] = 0;
	}
	else
	{
		string line;
		for (int i = 0; i < 9; i++) {
			getline(inFile, line);
			for (int j = 0; j < 9; j++) {
				seats[i][j] = line[j] - '0'; 
			}
		}
		inFile.close();
	}
}

void Admin::saveSeats()
{
	string seatPath;
	if (cinema == 1)
		seatPath = "cinemaCity\\Seats\\" + showName + ".txt";
	else if (cinema == 2)
		seatPath = "cinemaMax\\Seats\\" + showName + ".txt";
	
	ofstream outFile(seatPath);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{	
			outFile << seats[i][j];
		}
		outFile << endl;
	}
	outFile.close();
}

const double silverTicket = 8.0;
const double goldTicket = 12.0;
const double platinumTicket = 18.0;


void Admin::bookSeat()
{
	displayShow();
	cout << "Enter the name of the show: ";
	string name;
	cin >> name;
	loadSeats();

	cout << "\nSeat map (0-free, 1-taken):" << endl;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << seats[i][j] << ' ';
		}

		cout << "  <- " << tierFromRow(i) << endl;
	}

	cout << endl << "Enter seat to book:\n";
	cout << "Row (0-8): ";
	cin >> row;
	cout << "Col (0-8): ";
	cin >> col;


	if (row < 0 || row >= 9 || col < 0 || col >= 9)
	{
		cout << "Invalid seat position!" << endl;
		return;
	}

	if (seats[row][col] == 1)
	{
		cout << "This seat is already taken!" << endl;
		return;
	}

	string tier = tierFromRow(row);
	double price = priceFromRow(row);

	cout << endl << "Seat category: " << tier
		<< " | Ticket price: " << price << " lv" << endl << "Confirm (y/n)? ";
	char confirm;
	cin >> confirm;
	if (confirm != 'y' && confirm != 'Y')
	{
		cout << "Booking cancelled!" << endl;
		return;
	}

	seats[row][col] = 1;
	saveSeats();

	cout << "Seat successfully booked!" << endl;
	clearscreen();
	string cardNumber;
	string cardHolderFirst, cardHolderLast;
	string cardDate;
	string cvv;

	cout << "You hace to pay: " << price << "lv" << endl;
	cout << "Enter your 16-digit credit card number: ";
	cin >> cardNumber;
	if (cardNumber.length() != 16) {
		cout << "Incorrect input: Card number must be exactly 16 digits." << endl;
		return;
	}
	cout << "Enter the name on the card: ";
	cin >> cardHolderFirst >> cardHolderLast;
	cout << "Enter expiry date (MM/YY): ";
	cin >> cardDate;
	cout << "Enter the 3-digit CVV: ";
	cin >> cvv;
	if (cvv.length() != 3) {
		cout << "Incorrect input: CVV must be exactly 3 digits." << endl;
		return;
	}
	cout << "You paid successfully" << endl;
	cout << "Enjoy your projection";
}

static string tierFromRow(int r)
{
	if (r <= 2) return "Silver";
	if (r <= 5) return "Gold";
	return "Platinum";
}

static double priceFromRow(int r)
{
	if (r <= 2) return silverTicket;
	if (r <= 5) return goldTicket;
	return platinumTicket;
}