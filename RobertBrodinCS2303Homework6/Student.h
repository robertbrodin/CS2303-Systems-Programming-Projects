//
// Created by Eco on 2/19/2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
using namespace std;

class Newsie;

class Student {
private:
    string first_;
    string last_;
    float gpa_;
    int id_;
public:
    string full_name(string first_, string last_);
    int id();
    int gpa();
    void print_info();
    string getFullName();
    Student(string first, string last, float gpa, int id){first_ = first; last_ = last; gpa_ = gpa; id_ = id;}
    string getFirstName(){
        return first_;
    }
    string getLastName(){
        return last_;
    }

};

enum article {
    News,
    Opinions_n_Editorials,
    Features,
    Sports,
    Entertainment,
    Humor,
    NONE,
};

enum position {
    Editor,
    Deputy_Editor,
    Assistant_Editor,
    Reporter,
    Cub_Reporter,

};

position getPosition(int position);
article getArticle(int article);
string getArticleString(article anArticle);
string getTitle(position aPosition);

class assignment {
public:
    article desk;
    string temptitle;
    bool assigned;
    Newsie* assignedNewsie;
};


// TODO: Do I want position and article to be strings or booleans? It's kinda unnecessary as booleans, however, it might be easier than doing string comparison.
class Newsie: public Student{

public:
    //This is C style.  In HW6, you'll extend your Student (from HW5) class in C++
    position positionTitle;

    article primaryArticle;
    article secondaryArticle;
    article tertiaryArticle;

    int termGoal;
    int termCount;
    int terms;
    int assignmentCount;

    string nondeplume;

    assignment currentPriority;
    assignment currentExtra;
    assignment currentEmergency;

    vector<string> assignmentNames;

    Newsie(string firstName, string lastName, float GPA, int ID, position title, article primary, article secondary, article tertiary, int goal, int count, int term, string non): Student(firstName, lastName, GPA, ID){
        positionTitle = title;
        primaryArticle = primary;
        secondaryArticle = secondary;
        tertiaryArticle = tertiary;
        termGoal = goal;
        termCount = count;
        terms = term;
        nondeplume = non;
        assignmentCount = 0;
        currentPriority.desk = NONE;
        currentExtra.desk = NONE;
        currentEmergency.desk = NONE;
    }
    void printAssignments(Newsie myNewsie){
        if(myNewsie.assignmentNames.size() == 0){
            cout << "\n No Assignments!";
        }
        for(int i = 0; i < myNewsie.assignmentNames.size(); i++){
            string articleTitle = myNewsie.assignmentNames[i];
            replace(articleTitle.begin(), articleTitle.end(), '_', ' '); // replace all 'x' to 'y'
            cout << "\n" << (i + 1) << ". " << articleTitle;
        }
    }


    void printWeeklyRollCall(vector<Newsie> allWriters){

        for(int writerCount = 0; writerCount < allWriters.size(); writerCount++){
            cout << "\n";
            cout << "\n" << allWriters[writerCount].getFirstName() << " \"" << allWriters[writerCount].nondeplume << "\" " << allWriters[writerCount].getLastName() << ", " << getTitle(allWriters[writerCount].positionTitle) << ": ";
            printAssignments(allWriters[writerCount]);
        }
    }



    void removeCharsFromString(string &str, char* charsToRemove ) {
        for ( unsigned int i = 0; i < strlen(charsToRemove); ++i ) {
            str.erase( remove(str.begin(), str.end(), charsToRemove[i]), str.end() );
        }
    }

    void printWeeklyAssignmentDesk(vector<assignment> allAssignments){
        cout << "\n\nWeekly Assignment Desk:";
        for(int assignmentCount = 0; assignmentCount < allAssignments.size(); assignmentCount++){
            string writerTitle = getTitle(allAssignments[assignmentCount].assignedNewsie->positionTitle);
            replace(writerTitle.begin(), writerTitle.end(), '_', ' '); // replace all 'x' to 'y'
            string articleTitle = allAssignments[assignmentCount].temptitle;
            replace(articleTitle.begin(), articleTitle.end(), '_', ' '); // replace all 'x' to 'y'
            cout << "\n " << allAssignments[assignmentCount].assignedNewsie->getLastName() << ", " <<  writerTitle << " - " << articleTitle;
        }
    }


};



