#include "iostream"
#include "cmath"
#include "vector"

using namespace std;

int T;

int a, b, c, d;

int gcd(int a, int b) {
    return (a < b ? (
        gcd(b, a)
    ) : (
            b == 0 ? (
                a
            ) : (
                gcd(b, a % b)
            )
        )
    );
}

int main() {
    cin >> T;

    bool flag = false;

    for (int i = 0; i < T; ++i) {
        cin >> a >> b >> c >> d;

//  - 1
//        int ab = gcd(a, b);
//        int bc = gcd(b, c);
//        int cd = gcd(c, d);
//
//        int abc = gcd(ab, bc);
//        int bcd = gcd(bc, cd);
//
//        int abcd = gcd(abc, bcd);

//  - 2
//        flag = false;
//
//        for (int k = 2; k <= sqrt(min(min(a, b), min(c, d))); ++k) {
//            if (a % k == 0 && b % k == 0 && c % k == 0 && d % k == 0) {
//                cout << k << endl;
//                flag = true;
//                break;
//            }
//        }
//
//        if (!flag) {
//            cout << -1 << endl;
//        }

//  - 3
//        cout << endl;
        int ab = gcd(a, b);
        int bc = gcd(b, c);
        int cd = gcd(c, d);
//        cout << ab << ' ' << bc << ' ' << cd << endl;

        int abc = gcd(ab, bc);
        int bcd = gcd(bc, cd);
//        cout << abc << ' ' << bcd << endl;

        int abcd = gcd(abc, bcd);
//        cout << abcd << endl;
//        cout << endl;

        int mi = min(min(a, b), min(c, d));

//        if (abcd == 1) {
//            cout << -1 << endl;
//        } else if (abcd == mi) {
//            for (int k = 2; k <= mi; ++k) {
//                if (a % k == 0 && b % k == 0 && c % k == 0 && d % k == 0) {
//                    cout << k << endl;
//                    break;
//                }
//            }
//        } else {
//            cout << mi / abcd << endl;
//        }
        if (abcd == 1) {
            cout << -1 << endl;
        } else {
            for (int k = 2; k <= mi; ++k) {
                if (a % k == 0 && b % k == 0 && c % k == 0 && d % k == 0) {
                    cout << k << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
