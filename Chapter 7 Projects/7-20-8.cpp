/*
 * NAME: Christ Brown
 * CLASS: Computer Science 2
 * PROFFESSOR: Dr. Tracy Kocher
 * DATE: 01/30/2024
 * 
 * PROMPT: Build
 * Define a structure Student with a first name, last name, and course grade (A, B, C, D, or F). 
 * Write a program that reads input in which each line has the first and last name and course grade, 
 * separated by spaces. Upon reading the input, your program should print all students with grade A, 
 * then all students with grade B, and so on.
 * 
 * DETAIL: 
 * 
 * USE:
 * Run program, enter first name, last name, and scores and hit enter. The program will calculate the 
 * grade by averaging the scores by deviding the sum by the amount of scores.
 * 
 * SOURCES:
 * https://www.geeksforgeeks.org/smart-pointers-cpp/
 * https://www.w3schools.com/cpp/cpp_structs.asp
 * https://www.w3schools.com/cpp/cpp_pointers.asp
 * https://www.youtube.com/watch?v=9j5KkOC_goQ
 * https://www.youtube.com/watch?v=eNofmKYzje4&t=3s
 * 
 * and of course the zybooks.
 * 
 * */

#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>

/**
 * @brief Struct for a student with their name, grade, and quiz scores.
*/

struct Student{
    std::string firstName;
    std::string lastName;
    char grade;
};

int main() {

    std::vector<Student> students;
    char yes;

    do{
        Student student;
        std::cin >> student.firstName >> student.lastName >> student.grade;
        students.push_back(student);
        std::cout << "Continue? (y/n): " << std::endl;
        std::cin >> yes;

    } while (char(yes) == 'y' || char(yes) == 'Y');

    for(char grade = 'A'; grade <= 'F'; grade++){
        std::cout << "Students with grade " << grade << std::endl;
        std::cout << std::endl;

        for(const Student& student : students){
            if(student.grade == grade){
                std::cout << std::setw(10) << std::left << student.firstName 
                << std::setw(10) << std::left << student.lastName << " Grade: " 
                << student.grade << std::endl;
            }
        }
        std::cout << std::endl;
    }
    return 0;
    
}