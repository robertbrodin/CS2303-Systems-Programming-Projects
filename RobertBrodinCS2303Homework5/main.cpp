#include <iostream>
#include "Student.h"
#import <vector>
#include <string>
using namespace std;

std::vector<Student> path;
void print_students(vector<Student> &students) {
    for (int i = 0; i < students.size(); i++) {
        students[i].print_info();
    }
    // Iterates through the students vector, calling print_info() for each student.
}

vector<Student> find_failing_students(vector<Student> &students) {
    vector<Student> failing_students;
    cout << "\n";
    for (int j = 0 ; j < students.size(); j++) {

        if(students[j].gpa() < 1.0){
            students[j].print_info();
            failing_students.push_back(students[j]);
        }
    }

    // Iterates through the students vector, appending each student whose gpa is
    // less than 1.0 to the failing_students vector.

    return failing_students;
}

int main() {
    string first_name, last_name;
    float gpa;
    int id;
    char repeat;
    vector<Student> students;

    do {
        cout << "Enter student's first name: ";
        cin >> first_name;
        cout << "Enter student's last name: ";
        cin >> last_name;
        gpa = -1;
        while (gpa < 0 || gpa > 4) {
            cout << "Enter student's GPA (0.0-4.0): ";
            cin >> gpa;
        }
        cout << "Enter student's ID: ";
        cin >> id;
        students.push_back(Student(first_name, last_name, gpa, id));
        cout << "Add another student to database (Y/N)? ";
        cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    Student rob = Student("Rob", "Brodin", 3.5, 420);
    Student bigRob = Student("Big Rob", "Rob", 0.5, 42);
    Student badStudent = Student("Large Rob", "WPI", 0.0, 1);

    students.push_back(rob);
    students.push_back(bigRob);
    students.push_back(badStudent);

    cout << endl << "All students:" << endl;
    print_students(students);

    cout << endl << "Failing students:";
    find_failing_students(students);

    FILE *NewsiesFP;
    NewsiesFP = fopen("NewsiesStaffClipped.txt", "r");
    int sentinel;
    char firstname_[30];
    char lastname_[30];
    float gpa_;
    int IDnum_;
    string title_;
    int primary_;
    int secondary_;
    int tertiary_;
    int term_goal_;
    int term_kount_;
    int terms_;

    char non_de_plume_[30];
    fscanf(NewsiesFP, "%d", &sentinel);
    printf("\nAll Newsies:\n");
    vector<Student> newsies;
    for (int kount = 1; kount <= sentinel;kount++) {
        fscanf(NewsiesFP, "%s %s %f %d %d %d %d %d %d %d %d %s", firstname_, lastname_,
               &gpa_, &IDnum_, &title_, &primary_, &secondary_, &tertiary_, &term_goal_, &term_kount_, &terms_,
               non_de_plume_);

        Student* newStudent = new Student(firstname_, lastname_, gpa_, IDnum_);
        newStudent->setNewsie(title_, primary_, secondary_, tertiary_, term_goal_, term_kount_, terms_, non_de_plume_);
        newsies.push_back(*newStudent);
    }
    // Print a space and the word 'None' on the same line if no students are
    // failing.
    // Otherwise, print each failing student on a separate line.
    for(int i = 0; i < newsies.size(); i++){
        newsies[i].print_info();
    }

    cout << "\nFailing Newsies:";
    find_failing_students(newsies);
    return 0;
}




