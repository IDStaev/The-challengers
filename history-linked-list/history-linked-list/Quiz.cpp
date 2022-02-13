#include "Quiz.h"
#include <vector>
#include <string>
using namespace std;

Quiz::Quiz(string question, string answer, vector<string> incorrectAnswer)
{
	this->question = question;
	this->answer = answer;
	this->incorrectAnswer = incorrectAnswer;
}

void Quiz::setQuestion(string question)
{
	this->question = question;
}

void Quiz::setAnswer(string answer)
{
	this->answer = answer;
}

void Quiz::setIncorrectAnswer(vector<string> incorrectAnswer)
{
	this->incorrectAnswer = incorrectAnswer;
}

string Quiz::getQuestion()
{
	return question;
}

string Quiz::getAnswer()
{
	return answer;
}

vector<string> Quiz::getIncorrectAnswer()
{
	return incorrectAnswer;
}