std::string solution(int num) {
    std::string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string ans;
    while (num != 0) {
        int i = (num - 1) % 26 + 1;
        ans = s.at(i - 1) + ans;
        num = (num - 1) / 26 + 1;
    }
    return ans;
}
