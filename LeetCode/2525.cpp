class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool isBulky = length >= 10000 || width >= 10000 || height >= 10000 || (long long)length * width * height >= 1000000000;
        bool isHeavy = mass >= 100;

        if (isBulky && isHeavy) {
            return "Both";
        } else if (isBulky) {
            return "Bulky";
        } else if (isHeavy) {
            return "Heavy";
        } else {
            return "Neither";
        }
    }
};
