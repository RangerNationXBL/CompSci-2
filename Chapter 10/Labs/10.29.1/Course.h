#ifndef COURSEH
#define COURSEH

#include <iostream>
#include <string>

using namespace std;

class Course {
	// TODO: Declare private data members
private:
    string courseNumber;
    string courseTitle;

public:

	// TODO: Declare mutator functions 
	//       SetCourseNumber(), SetCourseTitle()
    void SetCourseNumber(const string& num);
    void SetCourseTitle(const string& title);


	// TODO: Declare accessor functions - 
	//       GetCourseNumber(), GetCourseTitle()
    string GetCourseNumber() const;
    string GetCourseTitle() const;

	// TODO: Declare PrintInfo()
    void PrintInfo() const;

};

#endif
