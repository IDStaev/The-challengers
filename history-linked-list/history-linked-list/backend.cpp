#include <iostream>
#include <conio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "backend.h"
#include "frontend.h"
#include "LinkedList.h"
#include "LinkedListFunctions.h"
#include "Quiz.h"

using namespace std;

string grayToBin(string gray)
{
	string	bin = gray;

	for (size_t i = 1; i < gray.size(); i++)
	{
		bin[i] = char(int(bin[i - 1]) ^ int(gray[i] - '0'));
	}

	return bin;
}

string grayToDec(string gray)
{
	//Converts gray to binary
	string bin = grayToBin(gray);
	int dec = 0;

	//Converts binary to decimal
	for (size_t i = 0; i < bin.size(); i++)
	{
		if (bin[i] == '1')
			dec += int(pow(2, bin.size() - i - 1));
	}

	return to_string(dec);
}

//Reverses a string
string swapStr(string str)
{
	char temp;

	for (size_t i = 0; i < str.size() / 2; i++)
	{
		temp = str[i];
		str[i] = str[str.size() - i - 1];
		str[str.size() - i - 1] = temp;
	}

	return str;
}

string decToBin(string dec)
{
	string bin;
	int n = stoi(dec);

	for (int i = 0; n > 0; i++, n/=2)
	{
		bin.push_back((n % 2) + '0');
	}

	return swapStr(bin);
}

string decToGray(string dec)
{
	//Converts decimal to binary
	string bin = decToBin(dec);
	string gray = bin;

	for (size_t i = 1; i < bin.size(); i++)
	{
		//Operates xor operation to every two bits
		gray[i] = char((int(bin[i - 1]) ^ int(bin[i] - '0')));
	}

	return gray;
}

//Initializes default uprisings to a head node
Node* initializeDefaultUprisings()
{
	Node* headDefault = new Node(decToGray("1040"), "Start of Uprising of Peter Delyan (ends in 1041)", "Peter Delyan is considered the grandson of Tsar Samuel, so he was proclaimed King of Bulgaria. It erupts in Belgrade.It covers the whole of Macedonia, Thessaly and reaches Thebes.Peter Delyan was blinded and the uprising was suppressed by his cousin Alusian.");
	insertLastNode(&headDefault, decToGray("1072"), "Start of Uprising of Georgi Voitech and Konstantin Bodin (ends in 1073)", "Leader - Georgi Voitech. It spread to Macedonia, Nis and Kosovo, but was defeated about a year later. Georgi Voiteh was executed and Konstantin Bodin was sent into exile in Syria, but managed to escape.");
	insertLastNode(&headDefault, decToGray("1185"), "Uprising of Assen and Peter", "The uprising was successful and the era of the Second Bulgarian Kingdom began.");
	insertLastNode(&headDefault, decToGray("1404"), "Start of Uprising of Constantine and Fruzhin (ends in 1417)", "The first uprising against the Ottomans, supported by Hungary and Wallachia.");
	insertLastNode(&headDefault, decToGray("1598"), "First Tarnovo Uprising", "In 1593 a war broke out between the Ottomans and the Habsburg Empire. Then the First Tarnovo Uprising began to take shape. Leaders are Theodore Balina and Dionysius Rally. A large-scale conspiracy network has been set up. The revolt was announced after the invasion of the Wallachian voivode Mircho Hrabri near Silistra. In Tarnovo, Theodore Balina was proclaimed king under the name Shishman IV. After the Wallachian detachments withdrew, the Ottomans captured and plundered Tarnovo.");
	insertLastNode(&headDefault, decToGray("1686"), "Second Tarnovo Uprising", "In 1686 the Second Tarnovo Uprising was declared in Tarnovo. The leader is Roscislav Stratimirovich. The conspiracy was exposed due to the betrayal of a Greek and some of the leaders were executed. The insurgents acted quickly and took control of Tarnovo, and the movement spread to Silistra, Gabrovo, Troyan and others. The Ottoman army was sent, which reached the former capital and captured it. Meanwhile, the rebels withdrew to the Gabrovo Balkans, where they formed a new detachment, reinforced by a detachment. Their last battle was near Sofia, where the revolt was finally put down.");
	insertLastNode(&headDefault, decToGray("1688"), "The Chiprovtsi Uprising", "Leaders are Petar Parcevic and Georgi Pejacevic. It is due to the Habsburg entry into Belgrade. The rebels captured Kutlovitsa (today's Montana), and Orthodox Bulgarians from the northwest rose with them. Hungarian Protestants helped the Ottomans, who subjugated the center of Chiprovets and suppressed the uprising.");
	insertLastNode(&headDefault, decToGray("1689"), "Uprising of Karpos", "Bulgarians from southwestern Macedonia are revolting, led by Karposh. Kumanovo and Skopje were captured, and Karposh was awarded the rank of general by Leopold I, but after the forced withdrawal of his army to the west, the Ottomans suppressed the revolt.");
	insertLastNode(&headDefault, decToGray("1829"), "Thracian Uprising", "It happened after the capture of Sozopol by the Russians. The population of Strandzha rose with modern weapons from the Russian army and captured Sliven. It spread all the way to Lozengrad and Luleburg, but with the signing of a truce between St. Petersburg and the High Gate, the insurgent detachments were disbanded.");
	insertLastNode(&headDefault, decToGray("1875"), "Stara Zagora Uprising", "Georgi Rakovski created the organized national liberation movement, the BRCC appeared, and Vasil Levski began to build his committee network. The goal is liberation through universal rebellion. An attempt to do so was made in 1875 with the so-called Stara Zagora Uprising. The revolution in Bosnia and Herzegovina is a favorable condition, which is why they decided to revolt, but make many mistakes, such as lack of preparation, have a weak committee network, and an unstable Central Committee. On the agreed date, only a small group of the Stara Zagora Committee took action.");
	insertLastNode(&headDefault, decToGray("1876"), "The April Uprising", "The Giurgiu Committee was formed in Romania, where it was decided to revolt in the spring of 1876. They divided Bulgaria into 5 districts: 1st - Tarnovo, 2nd - Sliven, 3rd - Vratsa, 4th - Plovdiv, 5th - Sofia. Difficulties arise from the very beginning. In the Tarnovo district the preparation starts only in February. Disputes over tactics arose in the Sliven district, and the will of the local voivodes to organize a large detachment instead of a mass uprising was ultimately imposed there. The main problem in the Vratsa district is the lack of weapons. The preparation is going best in the Plovdiv district, moved to Panagyurishte. May 1 has been set as the starting date at the meeting in Oborishte. The plan was thwarted by Nenko Terziiski, who revealed everything to the Turkish authorities. Zapties are trying to arrest Todor Kableshkov, forcing him to declare an uprising on April 20th. By sending the famous \"Bloody Letter\", one by one the settlements in the fourth district revolted. In Panagyurishte, Benkovski formed the \"Flying Detachment\". In a short time almost the whole of Srednogorie and some Rhodope villages. The Tarnovo district revolted almost a week later, and at the beginning of May the detachment of Stoil Voivoda began to operate in Sliven.In the Vratsa region, the apostles decided to wait for the arrival of Botev's detachment. In several days of fighting against numerous bashibozuk and Circassian companies, the rebels fought bravely, but the intervention of the Turkish army doomed their resistance to failure. Suppression of the uprising is ruthless. Later, Russia declared war on the Ottoman Empire, which in 1878 led to the liberation of Bulgaria.");
	insertLastNode(&headDefault, decToGray("1903"), "Ilinden-Preobrazhensko Uprising", "The emergence of the IMRO in 1893 marked the beginning of a more organized revolutionary activity in Macedonia and Edirne Thrace. In 1903 the last Bulgarian uprising against foreign rule broke out. It is considered the best organized, with according to various estimates nearly 26,000 people. In most counties, the main problem is the lack of training and weapons. At the same time, factors in a good end to the uprising were intensified Turkish repression and frequent clashes with soldiers. A compromise option is reached for a classical uprising only in the most prepared areas, and in the others � intensified activity without involving the population. The revolt broke out according to plan on July 20, 1903. in the Bitola Revolutionary District. Edirne Thrace is also rising. The tactics of a gradual outbreak of the uprising somewhat surprised the high gate, which sent thousands of regular troops. The Bulgarians fought bravely, and the uprising was put down only at the end of September, and in the Aegean part it lasted until the end of October. Ottoman units suppressed the movement in the Edirne region at the end of August. Like the April Uprising, the Ilinden-Preobrazhensk Uprising was brutally crushed. According to the memorandum of the IMRO to the great powers from 1904. Nearly 1,000 insurgents were killed in the battle, 201 villages were set on fire, 4,696 civilians were killed and more than 30,000 refugees fled to Bulgaria.");
	
	return headDefault;
}

bool checkIfValidYear(string year)
{
	//If empty
	if (year.size() == 0)
		return false;

	//Checks if its all digits
	for (size_t i = 0; i < year.size(); i++)
	{
		if (year[i] < '0' || year[i]>'9')
			return false;
	}

	//Checks if its existing year
	if (stoi(year) > 2022 || stoi(year) <= 0)
		return false;

	return true;
}

void addAnEvent(Node** head)
{
	addAnEventHeading();

	string year;
	string name;
	string info;

	cout << "Enter the year that the event had started: ";

	//Tries to enter the year
	try
	{
		getline(cin, year);
		
		//Checks if the year is valid
		if (!checkIfValidYear(year)) throw 0;
	}
	catch (...)
	{
		//While the year is not valid enter it again
		do
		{
			cout << "\n\tPlease enter a valid year: ";
			getline(cin, year);
		} while (!checkIfValidYear(year));
	}

	cout << "\nEnter the name of the event: ";
	getline(cin, name);

	cout << "\nEnter the information about the event: ";
	getline(cin, info);

	insertLastNode(head, decToGray(year), name, info);
}

//Displays the avalable nodes in the delete menu
void displayDeleteMenu(Node* head, int option)
{
	int nodeCount = getNodeCount(head);

	for (int i = 1; i <= nodeCount; i++)
	{
		if (i == option) cout << "->";
		else cout << "  ";

		cout << grayToDec(head->getYear()) << " | " << head->getName() << endl;

		head = head->getNext();
	}

	cout << endl;
	if (option == nodeCount + 1) cout << "->";
	else cout << "  ";
	cout << "Go back" << endl;
}

//Ensures that the user has entered valid command
bool checkIfValidUserImput(string userImput)
{
	if (userImput != "y" && userImput != "n" && userImput != "Y" && userImput != "N")
		return false;
	return true;
}

//Deletes a node at a given index
void deleteNode(Node* head, int index)
{
	for (int i = 1; i < index - 1; i++)
	{
		head = head->getNext();
	}

	Node* temp = head->getNext();
	head->setNext(head->getNext()->getNext());
	delete temp;
}

//Deletes the first node
void deleteFirstNode(Node** head)
{
	*head = (*head)->getNext();
}

//Runs the whole delete an event menu
bool deleteAnEvent(Node** head)
{
	int option = 1;
	int nodeCount = getNodeCount(*head);

	deleteAnEventHeading();
	displayDeleteMenu(*head, option);

	do
	{
		unsigned char ch1 = _getch();
		//Arrows
		if (ch1 == 224)
		{
			unsigned char ch2 = _getch();
			if (ch2 == 72)
			{
				if (option != 1)
				{
					option--;
				}
			}
			else if (ch2 == 80)
			{
				if (option != nodeCount + 1)
				{
					option++;
				}
			}
		}
		//Enter
		else if (ch1 == 13)
		{	
			if (option == nodeCount + 1)
			{
				//Go back
				return 0;
			}
			else
			{
				if ((*head)->getNext() == NULL)
				{
					cout << "\n  You must have at least one event!\n";
					if (_getch())
					{
						system("cls");
					}
				}
				else
				{
					//Ensures that the user wants to delete the event
					string userImput;
					cout << "\n  Are you sure you want to delete this event? (y/n): ";
					try
					{
						getline(cin, userImput);
						if (!checkIfValidUserImput(userImput))
							throw 0;
					}
					catch (...)
					{
						//While the user keeps enetring invalid command will ask again
						do
						{
							cout << "\tPlease eneter a valid command: ";
							getline(cin, userImput);
						} while (!checkIfValidUserImput(userImput));
					}

					//If the user has agreed on deleting
					if (userImput == "y" || userImput == "Y")
					{
						if (option == 1)
						{
							deleteFirstNode(&*head);
						}
						else
						{
							deleteNode(*head, option);
						}

						nodeCount--;
						cout << "  Done!\n";
					}
				}
			}
		}
		system("cls");

		deleteAnEventHeading();
		displayDeleteMenu(*head, option);

	} while (true);

	return 1;
}

//Initializes the questions for the quiz
vector<Quiz> initializeQuiz()
{
	vector<Quiz> quiz;
	quiz.push_back({ "Where does the uprising of Peter Delyan start?", "Belgrade", {"Tarnovo", "Sozopol"} });
	quiz.push_back({ "When did the uprising of Georgi Voitech and Konstantin Bodin started? ", "1072", {"1185", "1130"} });
	quiz.push_back({ "Which era began after the successful uprising of Assen and Peter?", "Second Bulgarian Kingdom", {"First Bulgarian Kingdom", "Third Bulgarian Kingdom"} });
	quiz.push_back({ "By whom was supported the uprising of Constantine and Fruzhin?", "Hungary and Wallachia", {"Ottoman Empire", "Serbia"} });
	quiz.push_back({ "Who were the leaders of First Tarnovo Uprising?", "Theodore Balina and Dionysius Rally", {"Vasil Levski", "Kiril and Metodii"} });
	quiz.push_back({ "When did the uprising of Karpos started?", "1689", {"1677", "1691"} });
	quiz.push_back({ "Where was the Giurgiu Committee formed?", "Romania", {"Bulgaria", "Turkey"} });
	quiz.push_back({ "When did Bulgaria liberate?", "1878", {"1880", "1914"} });
	quiz.push_back({ "When did Todor Kableshkov send the \"Bloody Letter\"? (1876)", "April 20th", {"May 1st", "March 3rd"} });

	return quiz;
}

//Displays the qestion and the answers in a random way based on a random number n
void displayQuestion(Quiz quiz, int option, int n)
{
	cout << quiz.getQuestion() << endl << endl;

	if (n % 2 == 0)
	{
		vector<string> temp = { quiz.getIncorrectAnswer()[1], quiz.getIncorrectAnswer()[0] };
		quiz.setIncorrectAnswer(temp);
	}

	option == 1 ? cout << "-> " : cout << "   ";
	n / 2 != 0 ? cout << quiz.getIncorrectAnswer()[0] << endl : cout << quiz.getAnswer() << endl;

	option == 2 ? cout << "-> " : cout << "   ";
	if (n / 2 == 0)
		cout << quiz.getIncorrectAnswer()[0] << endl;
	else if (n / 2 == 1)
		cout << quiz.getAnswer() << endl;
	else 
		cout << quiz.getIncorrectAnswer()[1] << endl;

	option == 3 ? cout << "-> " : cout << "   ";
	n / 2 != 2 ? cout << quiz.getIncorrectAnswer()[1] << endl : cout << quiz.getAnswer() << endl;
}

//Checks if the answer is correct
bool submitAnswer(int option, int r)
{
	if ((r == 0 || r == 1) && option == 1) return true;
	if ((r == 2 || r == 3) && option == 2) return true;
	if ((r == 4 || r == 5) && option == 3) return true;
	return false;
}

//Shuffles the questions randomly
vector<Quiz> randomizeQuiz(vector<Quiz> quiz)
{
	int n;

	for (size_t i = 0; i < quiz.size(); i++)
	{
		n = rand() % quiz.size();
		swap(quiz[i], quiz[n]);
	}

	return quiz;
}

//Runs the main quiz menu
bool runQuiz()
{
	srand(unsigned(time(NULL)));

	vector<Quiz> quiz = randomizeQuiz(initializeQuiz());
	int option = 1;
	int correct = 0;
	bool flag = true;

	quizHeading();

	for (size_t i = 0; i < quiz.size(); i++)
	{
		int r = rand() % 6;
		flag = true;

		do
		{
			cout << i + 1 << ". ";
			displayQuestion(quiz[i], option, r);

			unsigned char ch1 = _getch();
			if (ch1 == 224)
			{
				unsigned char ch2 = _getch();
				if (ch2 == 72)
				{
					if (option != 1)
					{
						option--;
					}
				}
				else if (ch2 == 80)
				{
					if (option != 3)
					{
						option++;
					}
				}
			}
			else if (ch1 == 13)
			{
				if (submitAnswer(option, r)) correct++;
				flag = false;
			}

			system("cls");
			quizHeading();
		} while (flag);
	}

	cout << "  FINAL SCORE: " << correct << " correct out of " << quiz.size() << "!\n";
	cout << "  You got " << double(correct) / double(quiz.size()) * 100 << "%\n\n";

	system("pause");

	return 0;
}

//Base function to run the program
bool runProgram()
{
	Node* headDefault = initializeDefaultUprisings();

	int counter = 1;

	printMenu(counter);

	//Changes arrow position of the menu
	do
	{
		unsigned char ch1 = _getch();
		if (ch1 == 224)
		{
			unsigned char ch2 = _getch();
			if (ch2 == 72)
			{
				if (counter != 1)
				{
					counter--;
				}
			}
			else if (ch2 == 80)
			{
				if (counter != 5)
				{
					counter++;
				}
			}

			system("cls");
			printMenu(counter);
		}

		//If user presses enter
		else if (ch1 == 13)
		{
			switch (counter)
			{
			case 1:
			{
				system("cls");
				displayList(headDefault);
				system("cls");

				printMenu(counter);

				break;
			}
			case 2:
			{
				system("cls");
				addAnEvent(&headDefault);
				system("cls");

				printMenu(counter);

				break;
			}
			case 3:
			{
				system("cls");
				while (deleteAnEvent(&headDefault))
				{
					deleteAnEvent(&headDefault);
				}
				system("cls");

				printMenu(counter);

				break;
			}
			case 4:
			{
				system("cls");
				while (runQuiz())
				{
					runQuiz();
				}
				system("cls");

				printMenu(counter);

				break;
			}
			case 5: return 0;
			}
		}
	} while (true);

	return 1;
}