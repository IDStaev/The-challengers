#include <iostream>
#include <string>
#include <conio.h>

#include "linkedList.h"
#include "LinkedListFunctions.h"
#include "backend.h"
#include "frontend.h"
using namespace std;

//Displays all the nodes of a linked list
void displayList(Node* node)
{
	allEventsHeading();

	while (node != NULL)
	{
		cout << grayToDec(node->getYear()) << " | ";
		cout << node->getName();

		unsigned char ch1 = _getch();
		if (ch1 == 224)
		{
			unsigned char ch2 = _getch();

			if (ch2 == 77)
				cout << " - " << node->getInfo();
		}

		cout << endl << endl;

		node = node->getNext();
	}

	system("pause");
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