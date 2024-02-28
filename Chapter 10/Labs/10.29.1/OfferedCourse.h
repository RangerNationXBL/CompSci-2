#ifndef OFFERED_COURSEH
#define OFFERED_COURSEH

#include "Course.h"

class OfferedCourse : public Course {
	// TODO: Declare private data members
private:
    string instructorName;
    string location;
    string classTime;

public:
	// TODO: Declare mutator functions -
	//      SetInstructorName(), SetLocation(), SetClassTime()
    void SetInstructorName(const string& name);
    void SetLocation(const string& location);
    void SetClassTime(const string& classTime);

	// TODO: Declare accessor functions -
	//      GetInstructorName(), GetLocation(), GetClassTime()

    string GetInstructorName() const;
    string GetLocation() const;
    string GetClassTime() const;

};

#endif