#pragma once
#include "LinkedList.h"
#include "Quiz.h"

string grayToBin(string gray);
string grayToDec(string gray);
string swapStr(string v);
string decToBin(string dec);
string decToGray(string dec);
Node* initializeDefaultUprisings();
bool checkIfValidYear(string year);
void addAnEvent(Node** head);
void displayDeleteMenu(Node* head, int option);
bool checkIfValidUserImput(string userImput);
void deleteNode(Node* head, int index);
void deleteFirstNode(Node** head);
bool deleteAnEvent(Node** head);
vector<Quiz> initializeQuiz();
void displayQuestion(Quiz quiz, int option, int n);
bool submitAnswer(int option, int r);
vector<Quiz> randomizeQuiz(vector<Quiz> quiz);
bool runQuiz();
bool runProgram();