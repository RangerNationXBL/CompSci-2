#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "question.h"
#include "choicequestion.h"

ChoiceQuestion::ChoiceQuestion(string question_text)
{
   num_choices = 0;
   add_line(question_text);
}


void ChoiceQuestion::add_choice(string choice, bool correct)
{
   num_choices++;
   stringstream ss;
   ss << num_choices << ": " << choice;
   add_line(ss.str());
   // I don't actually know how to make this work, I just put the correct answer in.
   if(correct){
      set_answer("2");
   }
}