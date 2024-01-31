// Name: Chris Brown
// Class: CompSci-2
// Date: 01/38/2024

/*
PROMPT:
Define a structure Student with a first name, last name, and course grade (A, B, C, D, or F). 
Write a program that reads input in which each line has the first and last name and course grade, 
separated by spaces. Upon reading the input, your program should print all students with grade A, 
then all students with grade B, and so on.

Enhance the program in Programming Project 7.20.8 so that each student has ten quiz scores. The input 
contains the student names and quiz scores but no course grades. The program should compute the course 
grade. If the sum of the quiz scores is at least 90, the grade is an A. If the sum is at least 80, 
the grade is a B, and so on. Then print all students with grade A together with their individual quiz 
scores, followed by all students with grade B, and so on.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>



// Create the structure

struct Student{ 
    std::string firstName;
    std::string lastName;
    char grade;
    //expand
    std::vector<int> quizScores;
    // end expand
};

void printStudent(const Student* Student){

    std::cout << "Student: " << Student->firstName << " " << Student->lastName << std::endl;
    std::cout << "Grade: " << Student->grade << std::endl;
    // expand
    std::cout << "Quiz Scores: ";
    for(int i = 0; i < Student->quizScores.size(); i++){
        std::cout << Student->quizScores[i] << " ";
    }
    //end expand

}

// unique_ptr takes responsibility of the pointer (Taking ownership) it is also responsible for deleting the pointer as well
// I have not fully read up on it so I only have a basic knowledge. 
// Unique_ptr has two components, a stored pointer and a stored deleter.

// This function adds the pointer to a vector of pointers "move" is used to transfer the object to another. 
// Many ways to use pointers as I have found.. My preferred is -> "arrow notatation" another is (*pointer).pointed "dot notation"

void addStudent(std::vector<std::unique_ptr<Student> > & students){
    std::unique_ptr<Student> newStudent(new Student());
    std::cout << "Please enter the student information (seperated by space or new line)" << std::endl;
    std::cin >> newStudent->firstName >> newStudent->lastName; // >> newStudent->grade;

    //expand
    std::cout << "Please enter the quiz scores (seperated by space or new line)" << std::endl;
    newStudent->quizScores.resize(10);
    for(int i = 0; i < 10; i++){
        std::cin >> newStudent->quizScores[i];
    }
    //end expand
    int totalScore = 0;
    for(int score : newStudent->quizScores){
        totalScore += score;
    }

    // Checking the average score for the student.
    double averageScore = static_cast<double>(totalScore) / newStudent->quizScores.size();
    if(averageScore >= 90){
        newStudent->grade = 'A';
    } else if (averageScore >= 80){
        newStudent->grade = 'B';
    } else if (averageScore >= 70){
        newStudent->grade = 'C';
    } else if (averageScore >= 60){
        newStudent->grade = 'D';
    } else {
        newStudent->grade = 'F';
    }
    //end expand

    students.push_back(std::move(newStudent));
}

// Just creates the desired output for the program.
// auto can be explicit like "string" probably should be in this case but I have string and char in struct.
void printStudentByGrade(const std::vector<std::unique_ptr<Student> > & students, char grade){
    for(const auto& student : students){
        if(student->grade == grade){
            printStudent(student.get());
        }
    }

}

// Making everything work. using a loop to get input and output the data
int main(){
    std::vector<std::unique_ptr<Student> > students;
    std::unique_ptr<Student> newStudent;

    char continueInput;
    do{
        addStudent(students);
        std::cout << "Do you want to enter a student? (Y/N)";
        std::cin >> continueInput;
    }while (continueInput == 'y' || continueInput == 'Y');

    for(char grade = 'A'; grade <= 'F'; grade++){
        std::cout << "\nStudents with Grade " << grade << ":\n";
        printStudentByGrade(students, grade);
    }
    
    return 0;
}