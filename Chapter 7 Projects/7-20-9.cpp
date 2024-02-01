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
 * PROMPT: Enhance
 * Enhance the program in Programming Project 7.20.8 so that each student has ten quiz scores. The input 
 * contains the student names and quiz scores but no course grades. The program should compute the course 
 * grade. If the sum of the quiz scores is at least 90, the grade is an A. If the sum is at least 80, 
 * the grade is a B, and so on. Then print all students with grade A together with their individual quiz 
 * scores, followed by all students with grade B, and so on.
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
 * TEST DATA:
 * John Doe 90 92 88 95 87 91 89 93 94 86
 * Jane Smith 78 82 80 79 81 85 77 83 84 76
 * Bob Johnson 68 72 70 69 71 75 67 73 74 66
 * Alice Williams 94 96 92 98 91 95 93 97 99 90
 * Charlie Brown 58 62 60 59 61 65 57 63 64 56
 * Eva Davis 88 82 90 79 81 85 87 83 84 86
*/

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
    std::vector<int> quizScores;
};
/**
 * @brief Computes the grade of a student based on their quiz scores.
 * 
 * @param quizScores a vector of quiz scores
 * @return the computed grade
 */
char computeGrade(std::vector<int>& quizScores){
    int sum = std::accumulate(quizScores.begin(), quizScores.end(), 0);
    double average = static_cast<double>(sum) / quizScores.size();
    std::cout << "Average: " << average << std::endl;
    std::cout << "Sum: " << sum << std::endl;

    if(average >= 90){return 'A';}
    else if(average >= 80){return 'B';}
    else if(average >= 70){return 'C';}
    else if(average >= 60){return 'D';}
    else {return 'F';}
}
void addStudent(std::vector<Student>& students){
    
    Student student;
    std::cout << "Please enter the student information: (first name, last name)" << std::endl;
    std::cin >> student.firstName >> student.lastName;
    if(student.firstName == "N" || student.firstName == "n"){exit(1);}
    std::cout << "Please enter the quiz scores: ";
    student.quizScores.resize(10);
    for(int i = 0; i < 10; i++){
        std::cin >> student.quizScores[i];
    }
    student.grade = computeGrade(student.quizScores);
    students.push_back(student);

}

int main() {

    std::vector<Student> students;
    char continueInput;

    do{
        addStudent(students);
        std::cout << "Would you like to add another student? (y/n): ";
        std::cin >> continueInput;
    }while(continueInput == 'y' || continueInput == 'Y');

    for(char grade = 'A'; grade <= 'F'; grade++){
        std::cout << "Students with grade " << grade << ": " << std::endl;
        for(const Student& student : students){
            if(student.grade == grade){
                std::cout << std::setw(10) << std::left << student.firstName << std::setw(10) << std::left << student.lastName << " ";
                for(int score : student.quizScores){
                    std::cout << score << " ";
                }
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    return 0;
    
}