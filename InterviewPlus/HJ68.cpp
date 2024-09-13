#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int score;
    Student(string name, int score): name(name), score(score) {}
};

int n;
int mode;
vector<Student> students;

string name;
int score;

int main(int argc, char const* argv[]) {
    cin >> n;
    cin >> mode;
    for (int k = 0; k < n; ++k) {
        cin >> name >> score;
        students.push_back(Student(name, score));
    }

    stable_sort(students.begin(), students.end(), [](const Student & a,
    const Student & b) {
        if (mode == 0) {
            return a.score > b.score;
        } else {
            return a.score <= b.score;
        }
    });

    for (auto& student : students) {
        cout << student.name << ' ' << student.score << endl;
    }

    return 0;
}
