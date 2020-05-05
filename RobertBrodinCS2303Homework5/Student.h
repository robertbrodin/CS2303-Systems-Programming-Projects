//
// Created by Eco on 2/19/2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
using namespace std;

class Student {
private:
    string first_;
    string last_;
    float gpa_;
    int id_;
    string title;
    int primary;
    int secondary;
    int tertiary;
    int termGoal;
    int termCount;
    int terms;
    string nondeplume;
public:
    string full_name(string first_, string last_);
    int id();
    int gpa();
    void print_info();
    string getFullName();
    Student(string first, string last, float gpa, int id){first_ = first; last_ = last; gpa_ = gpa; id_ = id;}
    void setNewsie(string title, int primary, int secondary, int tertiary, int termGoal, int termCount, int terms, string nonDepPlume);



};



