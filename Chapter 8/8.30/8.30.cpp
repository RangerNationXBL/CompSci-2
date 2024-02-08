/*
Write a program that reads the student information from a tab separated values (tsv) file. The program then creates a text file that records the course grades of the students. Each row of the tsv file contains the Last Name, First Name, Midterm1 score, Midterm2 score, and the Final score of a student. A sample of the student information is provided in StudentInfo.tsv. Assume the number of students is at least 1 and at most 20. Assume also the last names and first names do not contain whitespaces.

The program performs the following tasks:

Read the file name of the tsv file from the user.
Open the tsv file and read the student information.
Compute the average exam score of each student.
Assign a letter grade to each student based on the average exam score in the following scale:
A: 90 =< x
B: 80 =< x < 90
C: 70 =< x < 80
D: 60 =< x < 70
F: x < 60
Compute the average of each exam.
Output the last names, first names, exam scores, and letter grades of the students into a text 
file named report.txt. Output one student per row and separate the values with a tab character.
Output the average of each exam, with two digits after the decimal point, at the end of report.txt. 
Hint: Use the setprecision manipulator to format the output.
Ex: If the input of the program is:

StudentInfo.tsv
and the contents of StudentInfo.tsv are:

Barrett    Edan    70  45  59
Bradshaw    Reagan  96  97  88
Charlton    Caius   73  94  80
Mayo    Tyrese  88  61  36
Stern    Brenda  90  86  45
the file report.txt should contain:

Barrett    Edan    70  45  59  F
Bradshaw    Reagan  96  97  88  A
Charlton    Caius   73  94  80  B
Mayo    Tyrese  88  61  36  D
Stern    Brenda  90  86  45  C

Averages: midterm1 83.40, midterm2 76.60, final 61.60
*/

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int main() {
   string fileName;
   cin >> fileName;
   
   ifstream in(fileName);
   string lastName, firstName;
   int midterm1, midterm2, finalScore;
   double midterm1Total = 0;
   double midterm2Total = 0;
   double finalTotal = 0;
   int numStudents = 0;
   
   vector<string> students;
   while( in >> lastName >> firstName >> midterm1 >> midterm2 >> finalScore){
      double average = (midterm1 + midterm2 + finalScore) / 3.0;
      char grade;
      
      if(average >= 90){
         grade = 'A';
      }else if(average >= 80){
         grade = 'B';
      }else if(average >= 70){
         grade = 'C';
      }else if(average >= 60){
         grade = 'D';
      }else{
         grade = 'F';
      }
      
      students.push_back(lastName + "\t" + firstName + "\t" + to_string(midterm1) + "\t" + to_string(midterm2) + "\t" + to_string(finalScore) + "\t" + grade);
      
      midterm1Total += midterm1;
      midterm2Total += midterm2;
      finalTotal += finalScore;
      
      numStudents++;
   }
   in.close();
   
   double midterm1Average = midterm1Total / numStudents;
   double midterm2Average = midterm2Total / numStudents;
   double finalAverage = finalTotal / numStudents;
   
   ofstream out("report.txt");

   for(const auto& student : students){
    out << student << endl;
   }



   out << "\nAverages: midterm1 " << fixed << setprecision(2) << midterm1Average
       << ", midterm2 " << midterm2Average
       << ", final " << finalAverage << endl;
       
   out.close();
   return 0;
}
