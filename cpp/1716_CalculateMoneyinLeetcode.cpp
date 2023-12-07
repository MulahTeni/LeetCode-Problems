class Solution {
public:
    int totalMoney(int n) {
        int div7= n / 7;
        int rem7 = n % 7;
        int res = 0;
        
        for (int i = 0; i < div7; ++i) {
            res += i * 7 + 28;
        }
        for (int i = 1 + div7; i < 1 + div7 + rem7; ++i) {
            res += i;
        }
        return res;
    }
};