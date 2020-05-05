/*
 *
 *  Programmed by Nick Vachon, Robert Brodin, and Orest Ropi
 *  CS 2303, C Term 2020 WPI, Professor Engling
 *  Homework 5
 *
 */

#include "Student.h"
#include <string>
#include <vector>
#include <initializer_list>
#include <iomanip>
using namespace std;

string Student::full_name(string first_, string last_){
    return first_ + " " + last_;
}

int Student::id(){
    return id_;
}

int Student::gpa(){
    return gpa_;
}

void Student::print_info() {

    cout << getFullName() << " - "<< "GPA: " << setprecision(2) << fixed << gpa_ << " - ID: " << id_ << "\n";
}

string Student::getFullName(){
    return (first_ + " " + last_);
}

void Student::setNewsie(string titleA, int primaryA, int secondaryA, int tertiaryA, int termGoalA, int termCountA, int termsA, string nonDepPlumeA){
    title = titleA;
    primary = primaryA;
    secondary = secondaryA;
    tertiary = tertiaryA;
    termGoal = termGoalA;
    termCount = termCountA;
    terms = termsA;
    nondeplume = nonDepPlumeA;
}





