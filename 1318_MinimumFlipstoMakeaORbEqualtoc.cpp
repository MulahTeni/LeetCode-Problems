class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<30> aB(a);
        bitset<30> bB(b);
        bitset<30> cB(c);
        int count = 0;
        for(int i=0; i<aB.size(); i++){
            count += (cB[i]==1 && aB[i]==0 && bB[i]==0);
            count += (cB[i]==0 && aB[i]==1);
            count += (cB[i]==0 && bB[i]==1);
        }
        return count;
    }
};