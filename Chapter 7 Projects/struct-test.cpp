#include <iostream>

typedef struct{

    std::string fName;
    std::string lName;
    char grade;

} Student;


void createStudent(Student* student){
    std::vector<std::string> students;
    std::cout << "Please enter student info" << std::endl;
    std::cin >> student->fName >> student->lName >> student->grade;
    students.push_back(student);

}

int main(){
    
    Student* student;

    std::cin >> student->fName >> student->lName >> student->grade;

    
    return 0;
}