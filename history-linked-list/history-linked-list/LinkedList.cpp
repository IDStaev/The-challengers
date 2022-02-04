#include <iostream>
#include <string>
#include "linkedList.h"
using namespace std;

Node::Node(string year, string name, string info)
{
	this->year = year;
	this->name = name;
	this->info = info;
	next = NULL;
}

string Node::getYear()
{
	return year;
}

string Node::getName()
{
	return name;
}

string Node::getInfo()
{
	return info;
}

Node* Node::getNext()
{
	return next;
}

void Node::setYear(string year)
{
	this->year = year;
}

void Node::setName(string name)
{
	this->name = name;
}

void Node::setInfo(string info)
{
	this->info = info;
}

void Node::setNext(Node* nextNode)
{
	next = nextNode;
}