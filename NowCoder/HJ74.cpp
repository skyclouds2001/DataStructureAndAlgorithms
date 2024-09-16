#include <iostream>
#include <string>
#include <vector>

using namespace std;

string cmd;
string args;
bool flag = false;
vector<string> args_list;

int main(int argc, char const *argv[]) {
    getline(std::cin, cmd);

    for (auto c: cmd) {
        if (flag) {
            if (c == '"') {
                flag = false;
                if (args.length() != 0) {
                    args_list.push_back(args);
                }
                args = "";
            } else {
                args += c;
            }
        } else {
            if (c == '"') {
                flag = true;
            } else if (c == ' ') {
                if (args.length() != 0) {
                    args_list.push_back(args);
                }
                args = "";
            } else {
                args += c;
            }
        }
    }
    if (args.length() != 0) {
        args_list.push_back(args);
    }

    cout << args_list.size() << endl;

    for (auto s: args_list) {
        cout << s << endl;
    }

    return 0;
}
