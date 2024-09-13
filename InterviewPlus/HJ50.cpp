#include <iostream>
#include <string>
#include <stack>
#include <deque>

using namespace std;

bool DEBUG = false;

template<typename T>
void print_deque(deque<T>& q) {
    for (const T& v: q) {
        cout << v << ' ';
    }
    cout << endl;
}

int exec(const string& cmd) {
    if (DEBUG) cout << "cmd - begin - " << cmd << endl;

    deque<int> nums;
    deque<char> ops;

    /* transform command & resolve bracket */
    stack<char> inl;
    auto bg = cmd.begin();
    auto ed = cmd.end();
    string cm;
    int rt;
    if (*bg == '-') {
        cm += '-';
        ++bg;
    }
    for (; bg != ed;) {
        switch (*bg) {
            case '(':
            case '[':
            case '{':
                inl.push(*bg);
                ++bg;
                while (!inl.empty()) {
                    switch (*bg) {
                        case '(':
                        case '[':
                        case '{':
                            inl.push(*bg);
                            break;
                        case ')':
                        case ']':
                        case '}':
                            inl.pop();
                            break;
                    }
                    if (!inl.empty()) {
                        cm += *bg;
                    }
                    ++bg;
                }
                if (DEBUG) cout << "exec - begin - " << cm << endl;
                rt = exec(cm);
                nums.push_back(rt);
                if (DEBUG) cout << "exec - end - " << rt << endl;
                cm = "";
                break;
            case ')':
            case ']':
            case '}':
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                if (cm.length() > 0) {
                    nums.push_back(stoi(cm));
                    cm = "";
                }
                ops.push_back(*bg);
                ++bg;
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                cm += *bg;
                ++bg;
                break;
            default:
                break;
        }
    }
    if (cm.length() > 0) {
        nums.push_back(stoi(cm));
        cm = "";
    }

    if (DEBUG) cout << "nums - ";
    if (DEBUG) print_deque(nums);
    if (DEBUG) cout << "ops - ";
    if (DEBUG) print_deque(ops);

    /* mul & div */
    deque<int> nums_t;
    deque<char> ops_t;
    while (!nums.empty() && !ops.empty()) {
        char op = ops.front();
        if (op != '*' && op != '/') {
            int num = nums.front();
            nums_t.push_back(num);
            nums.pop_front();
            char op = ops.front();
            ops_t.push_back(op);
            ops.pop_front();
        } else {
            int num1 = nums.front();
            nums.pop_front();
            int num2 = nums.front();
            nums.pop_front();
            char op = ops.front();
            ops.pop_front();
            switch (op) {
                case '*':
                    nums.push_front(num1 * num2);
                    break;
                case '/':
                    nums.push_front(num1 / num2);
                    break;
            }
        }
    }
    if (!nums.empty()) {
        nums_t.push_back(nums.front());
        nums.pop_front();
    }
    nums = nums_t;
    ops = ops_t;

    if (DEBUG) cout << "nums - ";
    if (DEBUG) print_deque(nums);
    if (DEBUG) cout << "ops - ";
    if (DEBUG) print_deque(ops);

    /* add & sub */
    int opt = nums.front();
    nums.pop_front();
    while (!nums.empty() && !ops.empty()) {
        int num = nums.front();
        nums.pop_front();
        char op = ops.front();
        ops.pop_front();
        switch (op) {
            case '+':
                opt += num;
                break;
            case '-':
                opt -= num;
                break;
        }
    }

    if (DEBUG) cout << "nums - ";
    if (DEBUG) print_deque(nums);
    if (DEBUG) cout << "ops - ";
    if (DEBUG) print_deque(ops);

    if (DEBUG) cout << "cmd - end - " << opt << endl;

    return opt;
}

int main(int argc, char const *argv[]) {
    string cmd;
    cin >> cmd;

    int res = exec(cmd);

    cout << res << endl;

    return 0;
}
