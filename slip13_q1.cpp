// Write a C++ program to implement a class ‘student’ to overload following functions as follows:
// a. int maximum(int, int) – returns the maximum score of two students
// b. int maximum(int *a, int arraylength) – returns the maximum score from an array ‘a’
#include <iostream>
using namespace std;

class student {
public:
    int score;
public:
    student(int s) {
        score = s;
    }
    int maximum(int s1, int s2) {
        return (s1 > s2) ? s1 : s2;
    }
    int maximum(int *a, int arraylength) {
        int max_score = a[0];
        for (int i = 1; i < arraylength; i++) {
            if (a[i] > max_score) {
                max_score = a[i];
            }
        }
        return max_score;
    }
};

int main() {
    student s1(95), s2(90);
    int a[5] = { 70, 80, 85, 90, 95 };
    // Test the maximum() function for two students
    cout << "Max score between Student 1 and Student 2: " << s1.maximum(s1.score, s2.score) << endl;
    // Test the maximum() function for an array
    cout << "Max score from array: " << s1.maximum(a, 5) << endl;
}
