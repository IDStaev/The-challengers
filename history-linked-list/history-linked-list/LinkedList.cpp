#include <iostream>
#include <string>
#include "linkedList.h"
using namespace std;

//Constructor to the class
Node::Node(string year, string name, string info)
{
	setYear(year);
	setName(name);
	setInfo(info);

	//Automatically assigns NULL to next
	setNext(NULL);
}

//Get the year of an object
string Node::getYear()
{
	return year;
}

//Get the name of an object
string Node::getName()
{
	return name;
}

//Get the info of an object
string Node::getInfo()
{
	return info;
}

//Get the next node of a linked list
Node* Node::getNext()
{
	return next;
}

//Set the year of an object
void Node::setYear(string year)
{
	this->year = year;
}

//Set the name of an object
void Node::setName(string name)
{
	this->name = name;
}

//Set the info of an object
void Node::setInfo(string info)
{
	this->info = info;
}

//Set the next node of a linked list
void Node::setNext(Node* nextNode)
{
	next = nextNode;
}