#include <iostream>
#include <string>
#include <vector>

using namespace std;

const bool DEBUG = false;

int N;

vector<int> list;
int val;
int sum;
int sum5, sum3;

int size;
double target;

bool find(const vector<int>& list, const int pos, const int sum, const double& target) {
    const int size = list.size();
    
    if (sum == target) {
        return true;
    }
    if (pos >= size) {
        return false;
    }

    bool flag = false;

    for (int i = pos; i < size; ++i) {
        flag = flag || find(list, i + 1, sum + list[i], target);
        if (flag) {
            break;
        }
    }

    return flag;
}

int main(int argc, char const *argv[]) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> val;
        if (val % 5 == 0) {
            sum5 += val;
        } else if (val % 3 == 0) {
            sum3 += val;
        } else {
            list.push_back(val);
        }
        sum += val;
    }

    target = sum / 2.0 - sum5;
    
    if (DEBUG) cout << sum5 << ' ' << sum3 << ' ' << sum << endl;
    if (DEBUG) cout << target << endl;

    bool flag = find(list, 0, 0, target);
    
    cout << (flag ? "true" : "false") << endl;

    return 0;
}
