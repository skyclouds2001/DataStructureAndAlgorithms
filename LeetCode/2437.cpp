class Solution {
public:
    int countTime(string time) {
        int ans = 0, ch = 1, cm = 1;
        string h = time.substr(0, 2);
        string m = time.substr(3, 4);

        if (h == "??") {
            ch = 24;
        } else if (h[0] == '?') {
            if (h[1] == '0' || h[1] == '1' || h[1] == '2' || h[1] == '3') {
                ch = 3;
            } else {
                ch = 2;
            }
        } else if (h[1] == '?') {
            if (h[0] == '0' || h[0] == '1') {
                ch = 10;
            } else if (h[0] == '2') {
                ch = 4;
            }
        } else {
            ch = 1;
        }

        if (m == "??") {
            cm = 60;
        } else if (m[0] == '?') {
            cm = 6;
        } else if (m[1] == '?') {
            cm = 10;
        } else {
            cm = 1;
        }

        ans = ch * cm;

        return ans;
    }
};
