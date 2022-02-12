#include "Quiz.h"
#include <vector>
#include <string>
using namespace std;

Quiz::Quiz(string answ, vector<string> incorrectAnsw)
{
	answer = answ;
	incorrectAnswer = incorrectAnsw;
}

void Quiz::setAnswer(string answ)
{
	answer = answ;
}

void Quiz::setIncorrectAnswer(vector<string> incorrectAnsw)
{
	incorrectAnswer = incorrectAnsw;
}

string Quiz::getAnswer()
{
	return answer;
}

vector<string> Quiz::setIncorrectAnswer()
{
	return incorrectAnswer;
}