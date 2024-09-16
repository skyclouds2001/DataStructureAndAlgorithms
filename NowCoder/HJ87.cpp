#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
    string str;
    cin >> str;
    int len = str.length();

    int score = 0;

    if (len <= 4) {
        score += 5;
    } else if (len >= 5 && len <= 7) {
        score += 10;
    } else if (len >= 8) {
        score += 25;
    }

    int upper_cnt = 0, lower_cnt = 0, digit_cnt = 0, symbol_cnt = 0;

    for (char c: str) {
        if (isupper(c)) {
            upper_cnt++;
        } else if (islower(c)) {
            lower_cnt++;
        } else if (isdigit(c)) {
            digit_cnt++;
        } else {
            symbol_cnt++;
        }
    }

    if (upper_cnt == 0 && lower_cnt == 0) {
        score += 0;
    } else if (upper_cnt == 0 || lower_cnt == 0) {
        score += 10;
    } else if (upper_cnt != 0 && lower_cnt != 0) {
        score += 20;
    }

    if (digit_cnt == 0) {
        score += 0;
    } else if (digit_cnt == 1) {
        score += 10;
    } else if (digit_cnt >= 2) {
        score += 20;
    }

    if (symbol_cnt == 0) {
        score += 0;
    } else if (symbol_cnt == 1) {
        score += 10;
    } else if (symbol_cnt >= 2) {
        score += 25;
    }

    if (lower_cnt != 0 && upper_cnt != 0 && digit_cnt != 0 && symbol_cnt != 0) {
        score += 5;
    } else if (lower_cnt + upper_cnt != 0 && digit_cnt != 0 && symbol_cnt != 0) {
        score += 3;
    } else if (lower_cnt + upper_cnt != 0 && digit_cnt != 0) {
        score += 2;
    }

    string res;

    if (score >= 90) {
        res = "VERY_SECURE";
    } else if (score >= 80) {
        res = "SECURE";
    } else if (score >= 70) {
        res = "VERY_STRONG";
    } else if (score >= 60) {
        res = "STRONG";
    } else if (score >= 50) {
        res = "AVERAGE";
    } else if (score >= 25) {
        res = "WEAK";
    } else if (score >= 0) {
        res = "VERY_WEAK";
    }

    cout << res << endl;

    return 0;
}
