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


position getPosition(int position){
    enum position returnPosition = Reporter;
    switch(position){
        case 0:
            returnPosition = Editor;
            return returnPosition;
        case 1:
            returnPosition = Deputy_Editor;
            return returnPosition;
        case 2:
            returnPosition = Assistant_Editor;
            return returnPosition;
        case 3:
            returnPosition = Reporter;
            return returnPosition;
        case 4:
            returnPosition = Cub_Reporter;
            return returnPosition;
        default:
            returnPosition = Reporter;
            return returnPosition;

    }
}

article getArticle(int article){
    enum article returnArticle = NONE;
    switch(article){
        case 0:
            returnArticle = News;
            return returnArticle;
        case 1:
            returnArticle = Opinions_n_Editorials;
            return returnArticle;

        case 2:
            returnArticle = Features;
            return returnArticle;

        case 3:
            returnArticle = Sports;
            return returnArticle;

        case 4:
            returnArticle = Entertainment;
            return returnArticle;

        case 5:
            returnArticle = Humor;
            return returnArticle;

        default:
            returnArticle = NONE;
            return returnArticle;

    }
}

string getArticleString(article anArticle){
    string returnString;
    switch(anArticle){
        case News:
            return "News";
        case Opinions_n_Editorials:
            return "Opinions_n_Editorials";
        case Features:
            return "Features";
        case Sports:
            return "Sports";
        case Entertainment:
            return "Entertainment";
        case Humor:
            return "Humor";
        default:
            return "None";
    }
}

string getTitle(position aPosition){
    string returnString;
    switch(aPosition){
        case Editor:
            return "Editor";
        case Deputy_Editor:
            return "Deputy_Editor";
        case Assistant_Editor:
            return "Assistant_Editor";
        case Reporter:
            return "Reporter";
        case Cub_Reporter:
            return "Cub_Reporter";
        default:
            // THIS SHOULD NEVER HAPPEN (has to be one of these roles), if it does happen, the file input is incorrect.
            return "No role!";
    }
}

