/*
 * NAME: Christ Brown
 * CLASS: Computer Science 2
 * PROFFESSOR: Dr. Tracy Kocher
 * DATE: 01/26/2024
 * 
 * PROMPT: Build
 * Define a structure Student with a first name, last name, and course grade (A, B, C, D, or F). 
 * Write a program that reads input in which each line has the first and last name and course grade, 
 * separated by spaces. Upon reading the input, your program should print all students with grade A, 
 * then all students with grade B, and so on.
 * 
 * Sample Input:
 * First Name Last Name Course Grade
 * 
 * USE:
 * insert student information (first name, last name, and course grade), the hit enter to show the 
 * output of the students based on their course grade.
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>


/**
 * @brief structure
 * 
 * @details this structure is used to store the student information before moving it to the vector.
*/

struct Student{ 
    std::string firstName;
    std::string lastName;
    char grade;
};

// I am using a pointer here in the arguments of the function.
/**
 * @brief Prints a student's information
 * 
 * @param Student A pointer to the student's information
 * 
 * @details This function prints a student's information, including their first name, last name, and grade.
 */
void printStudent(const Student* Student) {
    std::cout << "Student: " << Student->firstName << " " << Student->lastName << std::endl;
    std::cout << "Grade: " << Student->grade << std::endl;
}


/**
 * @brief Adds a new student to the list of students
 * 
 * @param students The list of students
 * 
 * @details This function prompts the user to enter information about a new student, 
 * then adds the student to the list of students.
 * 
 * it uses a unique_ptr to store the student's information, this just makes sure that the memory is freed
 * after the function returns..
 */
void addStudent(std::vector<std::unique_ptr<Student> > & students) {
    std::unique_ptr<Student> newStudent(new Student());
    std::cout << "Please enter the student information (seperated by space or new line)" << std::endl;
    std::cin >> newStudent->firstName >> newStudent->lastName >> newStudent->grade;
    students.push_back(std::move(newStudent));
}

/**
 * @brief Prints a list of students with a specific grade
 * 
 * @param students The list of students
 * @param grade The grade to filter the students by
 * 
 * @details This function prints a list of students with a specific grade.
 * It iterates through the list of students and prints those with a matching grade.
 */
void printStudentByGrade(const std::vector<std::unique_ptr<Student> > & students, char grade) {
    for (const auto & student : students) {
        if (student->grade == grade) {
            printStudent(student.get());
        }
    }
}

/**
 * @brief Main function
 * 
 * @details This function is the main function of the program. It initializes the vector of students, 
 * and prompts the user to enter new students until the user enters 'n' or 'N'. After that, it 
 * prints all students with their grades.
 * 
 * @return int 
 */
int main() {
    std::vector<std::unique_ptr<Student> > students;  /**< vector of students */
    std::unique_ptr<Student> newStudent;                  /**< unique pointer to a new student */

    char continueInput;                                     /**< user input to continue adding students */
    do {
        addStudent(students);                               /**< add a new student to the vector */
        std::cout << "Do you want to enter a student? (Y/N): "; /**< prompt the user to enter a new student */
        std::cin >> continueInput;
    } while (continueInput == 'y' || continueInput == 'Y');

    for (char grade = 'A'; grade <= 'F'; grade++) {
        std::cout << "\nStudents with Grade " << grade << ":\n";
        printStudentByGrade(students, grade);               /**< print all students with the specified grade */
    }

    return 0;
}