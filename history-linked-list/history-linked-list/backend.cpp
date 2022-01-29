#include <iostream>
#include <conio.h>

#include "backend.h"
#include "frontend.h"

using namespace std;

bool runProgram()
{
	int counter = 1;
	
	printMenu(counter);
	
	do
	{
		unsigned char ch1 = _getch();
		if (ch1 == 224)
		{
			unsigned char ch2 = _getch();
			if (ch2 == 72)
			{
				if (counter == 1)
					counter = 5;
				counter--;
				system("cls");
			}
			else if (ch2 == 80)
			{
				if (counter == 4)
					counter = 0;
				counter++;
				system("cls");
			}
			printMenu(counter);
		}
		else if (ch1 == 13)
		{
			switch (counter)
			{
			case 1: cout << 1 << endl; break;
			case 2: cout << 2 << endl; break;
			case 3: cout << 3 << endl; break;
			case 4: return 0;
			}
		}
	} while (true);
	return 1;
}