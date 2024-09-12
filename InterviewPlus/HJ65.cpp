#include <iostream>
#include <string>

using namespace std;

string str_max, str_min;
int strlen_max, strlen_min;
string dp[300 + 1][300 + 1];
int max_i, max_j;
string max_str;

int main(int argc, char const *argv[]) {
    cin >> str_max >> str_min;
    if (str_max.length() < str_min.length()) {
        swap(str_max, str_min);
    }
    strlen_max = str_max.length();
    strlen_min = str_min.length();

    for (int i = 0; i < strlen_max; i++) {
        for (int j = 0; j < strlen_min; j++) {
            if (str_max[i] == str_min[j]) {
                dp[i + 1][j + 1] = dp[i][j] + str_max[i];
                if (dp[i + 1][j + 1].length() > max_str.length() || dp[i + 1][j + 1].length() == max_str.length() && max_j > j) {
                    max_i = i;
                    max_j = j;
                    max_str = dp[i + 1][j + 1];
                }
            }
        }
    }

    cout << max_str << endl;

    return 0;
}
