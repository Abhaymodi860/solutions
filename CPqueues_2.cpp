#include <iostream>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    
    int countCircular = 0, countSquare = 0;
    for (int student : students) {
        if (student == 0) countCircular++;
        else countSquare++;
    }

    for (int sandwich : sandwiches) {
        if (sandwich == 0) {
            if (countCircular > 0) {
                countCircular--;
            } else {
                break;
            }
        } else { 
            if (countSquare > 0) {
                countSquare--;
            } else {
                break;
            }
        }
    }
    return countCircular + countSquare;
}

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};

    int result = countStudents(students, sandwiches);
    cout << "Number of students unable to eat: " << result << endl;

    return 0;
}
