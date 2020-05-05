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

    for (int j = 0 ; j < students.size(); j++) {

        if(students[j].gpa() < 1.0){
            cout << "\n" << students[j].getFullName();
            failing_students.push_back(students[j]);
        }
    }

    // Iterates through the students vector, appending each student whose gpa is
    // less than 1.0 to the failing_students vector.

    return failing_students;
}

int main() {

    FILE *NewsiesFP;
    NewsiesFP = fopen("NewsiesStaffClipped.txt", "r");
    int sentinel;
    char firstname_[30];
    char lastname_[30];
    float gpa_;
    int IDnum_;
    int title_;
    int primary_;
    int secondary_;
    int tertiary_;
    int term_goal_;
    int term_kount_;
    int terms_;

    char non_de_plume_[30];
    fscanf(NewsiesFP, "%d", &sentinel);
    printf("\n\nNewsie Staff Info\n");
    vector<Newsie> newsies;
    for (int kount = 1; kount <= sentinel;kount++) {
        fscanf(NewsiesFP, "%s %s %f %d %d %d %d %d %d %d %d %s", firstname_, lastname_,
               &gpa_, &IDnum_, &title_, &primary_, &secondary_, &tertiary_, &term_goal_, &term_kount_, &terms_,
               non_de_plume_);
        // TODO: TITLE MIGHT BE AN ISSUE
        Newsie* newStudent = new Newsie(firstname_, lastname_, gpa_, IDnum_, getPosition(title_), getArticle(primary_), getArticle(secondary_), getArticle(tertiary_), term_goal_, term_kount_, terms_,
                                        non_de_plume_);

        newsies.push_back(*newStudent);
    }
    // Print a space and the word 'None' on the same line if no students are
    // failing.
    // Otherwise, print each failing student on a separate line.
    for(int i = 0; i < newsies.size(); i++){
        newsies[i].print_info();
    }

    fclose(NewsiesFP);

    FILE *AssignmentFP;
    AssignmentFP = fopen("AssignmentEditor.txt", "r");
    fscanf(AssignmentFP, "%d", &sentinel);
    cout << "\nThe new sentinel is: " << sentinel;

    int articleType;
    char articleTitle[200];

    vector<assignment> assignments;
    for (int kount = 1; kount <= sentinel;kount++) {
        fscanf(AssignmentFP, "%d %s", &articleType, articleTitle);

        assignment newAssignment;
        newAssignment.assigned = false;
        newAssignment.desk = getArticle(articleType);
        newAssignment.temptitle = articleTitle;

        assignments.push_back(newAssignment);
        // TODO: TITLE MIGHT BE AN ISSUE
    }

    for(int i = 0; i < assignments.size(); i++){
        cout << "\n " << assignments[i].temptitle << " - Type: " << getArticleString(assignments[i].desk);
    }

    // TODO: The code up until here is working -> March 1st, 2020 - 3:15PM

    for(int assignmentCount = 0; assignmentCount < assignments.size(); assignmentCount++){
        // While the assignment has no newsie attached, keep looking for one:
        int newsieCounter = 0;
        while(!assignments[assignmentCount].assigned){
            // If the newsie matches up with the type of the article (primary), add that article to the newsie and update the article to taken.
            if((newsies[newsieCounter].primaryArticle == assignments[assignmentCount].desk) and (newsies[newsieCounter].assignmentCount < 3)){
                // Taking into account the pointer! Setting it to the address of the newsie it was matched to.
                assignments[assignmentCount].assigned = true;
                assignments[assignmentCount].assignedNewsie = &newsies[newsieCounter];
                newsies[newsieCounter].currentPriority = assignments[assignmentCount];
                newsies[newsieCounter].assignmentCount = newsies[newsieCounter].assignmentCount + 1;
                newsies[newsieCounter].assignmentNames.push_back(assignments[assignmentCount].temptitle);
                //cout << "\n 1 running";
            }
            else if((newsies[newsieCounter].secondaryArticle == assignments[assignmentCount].desk) and (newsies[newsieCounter].assignmentCount < 3)){
                assignments[assignmentCount].assigned = true;
                assignments[assignmentCount].assignedNewsie = &newsies[newsieCounter];
                newsies[newsieCounter].currentExtra = assignments[assignmentCount];
                newsies[newsieCounter].assignmentCount = newsies[newsieCounter].assignmentCount + 1;
                newsies[newsieCounter].assignmentNames.push_back(assignments[assignmentCount].temptitle);

                //cout << "\n 2 running";

            }
            else if((newsies[newsieCounter].tertiaryArticle == assignments[assignmentCount].desk) and (newsies[newsieCounter].assignmentCount < 3)){
                assignments[assignmentCount].assigned = true;
                assignments[assignmentCount].assignedNewsie = &newsies[newsieCounter];
                newsies[newsieCounter].currentEmergency = assignments[assignmentCount];
                newsies[newsieCounter].assignmentCount = newsies[newsieCounter].assignmentCount + 1;
                newsies[newsieCounter].assignmentNames.push_back(assignments[assignmentCount].temptitle);

                //cout << "\n 3 running";

            }
            else{
                newsieCounter++;
            }
        }
    }

    newsies[0].printWeeklyRollCall(newsies);
    newsies[0].printWeeklyAssignmentDesk(assignments);


    fclose(AssignmentFP);

    return 0;
}




