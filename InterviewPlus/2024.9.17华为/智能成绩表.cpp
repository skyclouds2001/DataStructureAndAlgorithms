#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    vector<int> scores;
    int totalScore;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> subjects(m);
    for (auto subject : subjects) cin >> subject;
    vector<Student> students(n);
    for (Student& student : students) {
        cin >> student.name;
        student.scores.resize(m);
        for (int& score : student.scores) {
            cin >> score;
            student.totalScore += score;
        }
    }

    string sortSubject;
    cin >> sortSubject;

    auto it = find(subjects.begin(), subjects.end(), sortSubject);
    int sortIndex = (it != subjects.end()) ? distance(subjects.begin(), it) : -1;

    sort(students.begin(), students.end(), [sortIndex](const Student& a, const Student& b) {
        if(sortIndex != -1) {
            if(a.scores[sortIndex] != b.scores[sortIndex]){
                return a.scores[sortIndex] > b.scores[sortIndex];
            }
        } else
            if(a.totalScore != b.totalScore) {
                return a.totalScore > b.totalScore;
            }
        });

    return 0;
}
