#pragma once
#include <vector>
#include <string>
using namespace std;

class Quiz
{
public:
	Quiz(string question, string answ, vector<string> incorrectAnsw);
	void setQuestion(string question);
	void setAnswer(string answ);
	void setIncorrectAnswer(vector<string> incorrectAnsw);
	string getQuestion();
	string getAnswer();
	vector<string> getIncorrectAnswer();

private:
	string question;
	string answer;
	vector<string> incorrectAnswer;
};