/**
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
 * I am using new concepts that I find while reading up on programming. I understand them to the point 
 * I used them. The more I use advanced concepts, the more I feel confident that I can use them. 
 * 
 * USE:
 * Run program, enter first name, last name, and scores and hit enter. The program will calculate the 
 * grade by averaging the scores by deviding the sum by the amount of scores.
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <numeric>



/**
 * Student struct
 * This holds the variable for the student information.
 * this also holds the vector to store the quiz scores.
 * */

const int NUM_QUIZZES = 10;

struct Student{ 
    std::string firstName;
    std::string lastName;
    char grade;
    //expand
    std::vector<int> quizScores;
    // end expand
};

/**
 * @brief Prints a student's information to the console.
 * 
 * @param Student a pointer to the student's information.
 */
void printStudent(const Student* Student) {
    std::cout << "Student: " << Student->firstName << " " << Student->lastName << std::endl;
    std::cout << std::endl;
    std::cout << "Grade: " << Student->grade << std::endl;
    std::cout << std::endl;
    // expand
    std::cout << "Quiz Scores: ";
    
    for (int i = 0; i < Student->quizScores.size(); i++) {
        std::cout << Student->quizScores[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * Calculates the grade of a student based on their quiz scores.
 * This function uses the <numeric> header file to calculate the sum of the quiz scores.
 * its literally just an updated version of my original code. I moved it from add student
 * and made a function for it.
 * 
 * @param quizScores a vector of quiz scores
 * @return the calculated grade
 */
char calculateGrade(const std::vector<int>& quizScores) {
    int totalScore = std::accumulate(quizScores.begin(), quizScores.end(), 0);
    double averageScore = totalScore / quizScores.size();
    if (averageScore > 90) return 'A';
    else if (averageScore > 80) return 'B';
    else if (averageScore > 70) return 'C';
    else if (averageScore > 60) return 'D';
    else return 'F';
}

/**
 * Adds a new student to the list of students.
 * This function uses the <algorithm> header file to sort the list of students by last name, 
 * my previous version of this function also calculated the grade for the student. I moved
 * that into its own function. You can see the changes in the history of github.
 * 
 * @param students a reference to the list of students
 */
void addStudent(std::vector<std::unique_ptr<Student> >& students) {
    std::unique_ptr<Student> newStudent(new Student());
    std::cout << "Please enter the student information (separated by space): " << std::endl;
    std::cin >> newStudent->firstName >> newStudent->lastName; // >> newStudent->grade;
    std::cout << "Please enter the quiz scores (separated by space): " << std::endl;
    newStudent->quizScores.resize(10);

    for (int i = 0; i < NUM_QUIZZES; i++) {
        std::cin >> newStudent->quizScores[i];
    }

    newStudent->grade = calculateGrade(newStudent->quizScores); 
    students.push_back(std::move(newStudent));
}

/**
 * Prints all students with a specific grade.
 *
 * @param students a reference to the list of students
 * @param grade the grade to search for
 */
void printStudentByGrade(const std::vector<std::unique_ptr<Student> > & students, char grade) {
    for (const auto & student : students) {
        if (student->grade == grade) {
            printStudent(student.get());
        }
    }
}

/**
 * @brief Main function of the program.
 * 
 * This function initializes the list of students, adds students to the list if the user wishes to do so, 
 * and then prints all students with their grades.
 * 
 * @return int always returns 0
 */
int main() {
    std::vector<std::unique_ptr<Student> > students;  ///< List of students.
    std::unique_ptr<Student> newStudent;              ///< Temporary variable to hold new student information.

    char continueInput;  ///< User input to continue adding students.

    do {
        addStudent(students);  ///< Adds a new student to the list.
        std::cout << "Do you want to enter a student? (Y/N): ";
        std::cin >> continueInput;  ///< Reads user input.
    } while (continueInput == 'y' || continueInput == 'Y');  ///< Continues adding students until the user enters 'n' or 'N'.

    for (char grade = 'A'; grade <= 'F'; grade++) {
        std::cout << "\nStudents with Grade " << grade << ":\n";
        std::cout << std::endl;
        printStudentByGrade(students, grade);  ///< Prints all students with the specified grade.
    }

    return 0;
}