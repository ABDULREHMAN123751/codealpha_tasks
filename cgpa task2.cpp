#include <iostream>
#include <vector>

using namespace std;

struct Course {
    string name;
    double grade;
    int credit;
};

double calculateGPA(const vector<Course>& courses) {
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (size_t i = 0; i < courses.size(); i++) { // Fixed loop
        totalGradePoints += courses[i].grade * courses[i].credit;
        totalCredits += courses[i].credit;
    }

    return (totalCredits == 0) ? 0.0 : totalGradePoints / totalCredits;
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);

    for (int i = 0; i < numCourses; i++) {
        cout << "\nEnter details for course " << i + 1 << ":\n";
        cout << "Course Name: ";
        cin >> courses[i].name;
        cout << "Grade (on a scale of 0 to 4): ";
        cin >> courses[i].grade;
        cout << "Credit Hours: ";
        cin >> courses[i].credit;
    }

    double cgpa = calculateGPA(courses);

    cout << "\nCourse Details:\n";
    for (int i = 0; i < numCourses; i++) { // Fixed loop
        cout << "Course: " << courses[i].name << ", Grade: " << courses[i].grade 
             << ", Credits: " << courses[i].credit << "\n";
    }

    cout << "\nYour CGPA is: " << cgpa << "\n";
    return 0;
}
