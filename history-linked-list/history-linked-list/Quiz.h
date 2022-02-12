#pragma once
#include <vector>
#include <string>
using namespace std;

class Quiz
{
public:
	Quiz(string answ, vector<string> incorrectAnsw);
	void setAnswer(string answ);
	void setIncorrectAnswer(vector<string> incorrectAnsw);
	string getAnswer();
	vector<string> setIncorrectAnswer();

private:
	string answer;
	vector<string> incorrectAnswer;
};