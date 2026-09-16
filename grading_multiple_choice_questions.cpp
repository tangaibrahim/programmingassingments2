#include <iostream>

using namespace std;

int main() {
    // 2D array storing the answers for 8 students across 10 questions
    char answers[8][10] = {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}
    };

    // 1D array storing the answer key for the 10 questions
    char key[10] = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

    // Variables to hold array dimensions
    int numStudents = 8;
    int numQuestions = 10;

    // Iterate through each student
    for (int i = 0; i < numStudents; i++) {
        int correctCount = 0; // Reset score for the current student
        
        // Iterate through each question for the current student
        for (int j = 0; j < numQuestions; j++) {
            // Compare the student's answer to the answer key
            if (answers[i][j] == key[j]) {
                correctCount++;
            }
        }
        
        // Display the result
        cout << "Student " << i << "'s correct count is " << correctCount << endl;
    }

    return 0;
}
