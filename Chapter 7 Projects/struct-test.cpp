#include <iostream>
#include <vector>

struct Student{
    std::string firstName;
    std::string lastName;
    char grade;
    std::vector<int> scores;
};

void printStudent(Student* students){


}

void insertStudent(){
}

int main(){
    Student* student;
    std::vector<Student*> students;
    std::cin >> student->firstName >> student->lastName >> student->grade;
    students.push_back(student);
    std::cout << student->firstName << " " << student->lastName << " " << student->grade << std::endl;

    return 0;
}

