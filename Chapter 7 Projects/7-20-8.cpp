#include <iostream>
#include <vector>
#include <memory>

struct Student{ // Structures are initially public while class is initially private
    // The variables that will be used.
    std::string firstName;
    std::string lastName;
    char grade;
};

void printStudent(const Student* Student){

    // could use (*student).firstName instead of course I use arrow notation instead.

    std::cout << "Student: " << Student->firstName << " " << Student->lastName << std::endl;
    std::cout << "Grade: " << Student->grade << std::endl;

}

// This one failed to produce the results I wanted.

/* void addStudent(const std::vector<Student*> students){
    Student* newStudent = new Student;
    std::cout << "Please enter the student information:" << std::endl;
    std::cin >> newStudent->firstName >> newStudent->lastName >> newStudent->grade;
    students.push_back(newStudent);

} */

// Found a way to make it work correctly.

void addStudent(std::vector<std::unique_ptr<Student>>& students){
    std::unique_ptr<Student> newStudent = std::make_unique<Student>();
    std::cout << "Please enter the student information (seperated by space or new line)" << std::endl;
    std::cin >> newStudent->firstName >> newStudent->lastName >> newStudent->grade;
    students.push_back(std::move(newStudent));
}

int main(){

    

    std::vector<Student*> students; 
    Student* student = new Student;
    std::cin >> student->firstName >> student->lastName >> student->grade; 

    students.push_back(student);

    std::cout << student->firstName << " " << student->lastName << " " << student->grade << std::endl;

    // To prevent memory leaks.
    delete student;

    return 0;
}