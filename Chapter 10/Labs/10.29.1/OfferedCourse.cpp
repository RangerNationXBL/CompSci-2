#include "OfferedCourse.h"

// TODO: Define mutator functions -
//      SetInstructorName(), SetLocation(), SetClassTime()
void OfferedCourse::SetInstructorName(const string& name){
    instructorName = name;
}

void OfferedCourse::SetLocation(const string& loc){
    location = loc;
}

void OfferedCourse::SetClassTime(const string& time){
    classTime = time;
}


// TODO: Define accessor functions -
//      GetInstructorName(), GetLocation(), GetClassTime()
string OfferedCourse::GetInstructorName() const {
    return instructorName;
}

string OfferedCourse::GetLocation() const {
    return location;
}

string OfferedCourse::GetClassTime() const {
    return classTime;
}