//#include "Show.h"
//#include "menu.h"

//void Show::addShow()
//{
//	cout << endl << endl;
//	std::filesystem::path path;
//
//	if (admin.cinema == 1)
//		path = "cinemaCity\\Movie";
//	else if (admin.cinema == 2)
//		path = "cinemaMax\\Movie";
//	for (const auto& e : fs::directory_iterator(path))
//	{
//		if (e.is_regular_file())
//			std::cout << e.path().filename() << std::endl;
//	}
//	cout << "Which movie you want to select" << endl;
//	string name;
//	cin >> name;
//	cout << "Enter show date" << endl;
//	Show show;
//	string date;
//	cin >> date;
//	show.projectionDate = date;
//	show.filmTittle = name;
//	cout << "Choose seat type, you can choose from: Silver, Gold and Platinum" << endl;
//	string type;
//	cin >> type;
//
//	if (type == "Silver" || type == "Gold" || type == "Platinum")
//		show.typeOfSeat = type;
//
//	string current;
//	if (admin.cinema == 1)
//		 current = "cinemaCity\\Show\\";
//	else if (admin.cinema == 2)
//		current = "cinemaMax\\Show\\";
//
//	ofstream fileShow(current + name + ".txt");
//	show.filmTittle = name;
//	show.projectionDate = date;
//	show.typeOfSeat = type;
//
//	fileShow << show.filmTittle << endl;
//	fileShow << show.projectionDate << endl;
//	fileShow << show.typeOfSeat << endl;
//
//	fileShow.close();
//}