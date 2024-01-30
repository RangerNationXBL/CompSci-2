// Name: Chris Brown
// Class: CompSci-2
// Date: 01/38/2024

/*
PROMPT:
Define a structure Student with a first name, last name, and course grade (A, B, C, D, or F). 
Write a program that reads input in which each line has the first and last name and course grade, 
separated by spaces. Upon reading the input, your program should print all students with grade A, 
then all students with grade B, and so on.
*/

#include <iostream>
#include <vector>
#include <algorithm>


// Create the structure

struct Student{ 
    std::string firstName;
    std::string lastName;
    char grade;
};

// I am using a pointer here in the arguments of the function.
void printStudent(const Student* Student){

    std::cout << "Student: " << Student->firstName << " " << Student->lastName << std::endl;
    std::cout << "Grade: " << Student->grade << std::endl;

}

// unique_ptr takes responsibility of the pointer (Taking ownership) it is also responsible for deleting the pointer as well
// I have not fully read up on it so I only have a basic knowledge. 
// Unique_ptr has two components, a stored pointer and a stored deleter.

// This function adds the pointer to a vector of pointers "move" is used to transfer the object to another. 
// Many ways to use pointers as I have found.. My preferred is -> "arrow notatation" another is (*pointer).pointed "dot notation"

void addStudent(std::vector<std::unique_ptr<Student> > & students){
    std::unique_ptr<Student> newStudent(new Student());
    std::cout << "Please enter the student information (seperated by space or new line)" << std::endl;
    std::cin >> newStudent->firstName >> newStudent->lastName >> newStudent->grade;
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