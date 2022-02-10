#pragma once
#include "LinkedList.h"

string decToGray(string dec);
string decToBin(string dec);
string swapStr(string v);
string grayToDec(string gray);
string grayToBin(string gray);
bool checkIfValidYear(string year);
void addAnEvent(Node** head);
void deleteAnEvent(Node** head);
void displayDeleteMenu(Node* head, int option);
bool runProgram();
Node* initializeDefaultUprisings();