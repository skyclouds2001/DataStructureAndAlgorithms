#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
    int year, month, day;
    cin >> year >> month >> day;

    int days = 0;
    for (int i = 1; i < month; ++i) {
        switch (i) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                days += 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                days += 30;
                break;
            case 2:
                if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                    days += 29;
                } else {
                    days += 28;
                }
                break;
            default:
                break;
        }
    }
    days += day;

    cout << days << endl;

    return 0;
}
