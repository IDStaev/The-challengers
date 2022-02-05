#include <iostream>
#include <string>
#include "linkedList.h"
#include "LinkedListFunctions.h"
using namespace std;

//Displays all the nodes of a linked list
void displayList(Node* node)
{
	system("cls");
	while (node != NULL)
	{
		cout << node->getYear() << ", ";
		cout << node->getName() << ", ";
		cout << node->getInfo() << endl << endl;

		node = node->getNext();
	}
}

//Inserts a node at the beginning of a linked list
void insertFirstNode(Node** head, string y, string n, string d)
{
	Node* newNode = new Node(y, n, d);
	newNode->setNext(*head);
	*head = newNode;
}

//Inserts a node at the end of a linked list
void insertLastNode(Node** head, string y, string n, string d)
{
	Node* newNode = new Node(y, n, d);

	//Checks if the list is empty
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}

	Node* tail = *head;
	while (tail->getNext() != NULL)
	{
		tail = tail->getNext();
	}

	tail->setNext(newNode);
}

//Inserts a node after a given index
void insertAt(Node* prev, string y, string n, string d)
{
	if (prev == NULL)
	{
		cout << "Can't insert\n";
		return;
	}

	Node* newNode = new Node(y, n, d);

	newNode->setNext(prev->getNext());
	prev->setNext(newNode);
}