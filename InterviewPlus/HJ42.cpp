#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

string get_digit(int num) {
    switch (num) {
        case 0: return "";
        case 1: return "one ";
        case 2: return "two ";
        case 3: return "three ";
        case 4: return "four ";
        case 5: return "five ";
        case 6: return "six ";
        case 7: return "seven ";
        case 8: return "eight ";
        case 9: return "nine ";
        default: return "";
    }
}

string get__digit(int num) {
    switch (num) {
        case 2: return "twenty ";
        case 3: return "thirty ";
        case 4: return "forty ";
        case 5: return "fifty ";
        case 6: return "sixty ";
        case 7: return "seventy ";
        case 8: return "eighty ";
        case 9: return "ninety ";
        default: return "";
    }
}

string get___digit(int num) {
    switch (num) {
        case 10: return "ten ";
        case 11: return "eleven ";
        case 12: return "twelve ";
        case 13: return "thirteen ";
        case 14: return "fourteen ";
        case 15: return "fifteen ";
        case 16: return "sixteen ";
        case 17: return "seventeen ";
        case 18: return "eighteen ";
        case 19: return "nineteen ";
        default: return "";
    }
}

string analyze(int n, int depth = 0) {
    if (n >= 1000000) {
        return analyze(n / 1000000, 2) +
                analyze(n / 1000 % 1000, 1) +
                analyze(n % 1000, 0);
    }

    if (n >= 1000) {
        return analyze(n / 1000 % 1000, 1) +
                analyze(n % 1000, 0);
    }

    int th = n / 100;
    int se = n / 10 % 10;
    int fi = n % 10;
    string res = "";

    if (th != 0) {
        res += get_digit(th);
        res += "hundred ";
    }

    if (th != 0 && (se != 0 || fi != 0)) {
        res += "and ";
    }

    if (se != 1 && se != 0) {
        res += get__digit(se);
        res += get_digit(fi);
    } else if (se == 1) {
        res += get___digit(se * 10 + fi);
    } else {
        res += get_digit(fi);
    }

    if (depth == 2 && n != 0) {
        res += "million ";
    } else if (depth == 1 && n != 0) {
        res += "thousand ";
    }

    return res;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    string ans = analyze(n);
    cout << ans << endl;

    return 0;
}
