#pragma once
#include <string>
#include "LinkedList.h"
using namespace std;

void displayList(Node* node);
void insertFirstNode(Node** head, string y, string n, string d);
void insertLastNode(Node** head, string y, string n, string d);
void insertAt(Node* prev, string y, string n, string d);
int getNodeCount(Node* node);