#pragma once
#include "LinkedList.h"

string decToGray(string dec);
string decToBin(string dec);
string swapStr(string v);
string grayToDec(string gray);
string grayToBin(string gray);
bool checkIfValidYear(string year);
bool checkIfValidUserImput(string userImput);
void addAnEvent(Node** head);
bool deleteAnEvent(Node** head);
void displayDeleteMenu(Node* head, int option);
void deleteNode(Node* head, int index);
void deleteFirstNode(Node** head);
bool runQuiz();
bool submitAnswer(int option, int r);
bool runProgram();
Node* initializeDefaultUprisings();