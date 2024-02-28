#include <iostream>
#include <string>
using namespace std;

#include "question.h"

Question::Question() 
{
}

void Question::add_line(string line)   
{
   text = text + line + "\n";
}

void Question::set_answer(string correct_response)
{
   answer = correct_response;
}

bool Question::check_answer(string response) const
{
   return response == answer;
}

void Question::display() const
{
   cout << text << endl;
}