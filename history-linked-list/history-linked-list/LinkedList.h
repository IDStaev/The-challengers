#pragma once
#include <string>
using namespace std;

class Node
{
public:
	Node(string year, string name, string info);
	string getYear();
	string getName();
	string getInfo();
	Node* getNext();
	void setNext(Node* nextNode);

private:
	string year;
	string name;
	string info;
	Node* next;
};