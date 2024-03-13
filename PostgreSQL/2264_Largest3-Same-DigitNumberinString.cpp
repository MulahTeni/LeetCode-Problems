class Solution {
public:
    string largestGoodInteger(string num) {
        if (num.length() < 3) return "";
        char c = '+';
        for (int i = 0; i < num.length() - 2; ++i) {
            if (num[i] == num[i + 1] && num[i] == num[i+2]) {
                if (num[i] > c) c = num[i];
            }
        }
        if (c == '+') return "";
        return string(3,c);
    }
};