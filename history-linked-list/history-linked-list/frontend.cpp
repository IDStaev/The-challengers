#include <iostream>
#include <iomanip>
#include <string>

#include "frontend.h"

using namespace std;

void printMenuHeading()
{
    cout << "  _   _ _     _                     _   _                _ _\n";
    cout << " | | | (_)___| |_ ___  _ __ _   _  | |_(_)_ __ ___   ___| (_)_ __   ___ \n";
    cout << " | |_| | / __| __/ _ \\| '__| | | | | __| | '_ ` _ \\ / _ \\ | | '_ \\ / _ \\ \n";
    cout << " |  _  | \\__ \\ || (_) | |  | |_| | | |_| | | | | | |  __/ | | | | |  __/ \n";
    cout << " |_| |_|_|___/\\__\\___/|_|   \\__, |  \\__|_|_| |_| |_|\\___|_|_|_| |_|\\___| \n";
    cout << "                            |___/                                        \n\n\n";
}

void printMenuOptions(int option, string arrow)
{
    
    cout << setw(33);
    if (option == 1)cout << "=>";
    else cout << "  ";
    cout << " All Events\n";

    cout << setw(33);
    if (option == 2)cout << "=>";
    else cout << "  ";
    cout << " Add an event\n";

    cout << setw(33);
    if (option == 3)cout << "=>";
    else cout << "  ";
    cout << " Delete an event\n";

    cout << setw(33);
    if (option == 4)cout << "=>";
    else cout << "  ";
    cout << " Quiz\n";

    cout << setw(33);
    if (option == 5)cout << "=>";
    else cout << "  ";
    cout << " Exit\n";
}

void printMenu(int option)
{
    printMenuHeading();
    printMenuOptions(option);
}