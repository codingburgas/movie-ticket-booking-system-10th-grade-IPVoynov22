#include "menu.h"


int main()
{
    ifstream findFile("Users\\adminData.txt");
    if (!findFile.is_open())
    {
        ofstream createFile("Users\\adminData.txt");
        createFile << "admin" << endl;
        createFile << "admin" << endl;
        createFile.close();
    }
    else
    {
        findFile.close();
    }
    menuChoice();
}
