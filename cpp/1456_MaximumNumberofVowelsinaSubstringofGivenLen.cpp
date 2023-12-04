class Solution {
public:
    int isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c== 'o' || c=='u')    return 1;
        return 0;
    }
    int maxVowels(string s, int k) {
        int res = 0;
        for(auto c = s.begin(); c<s.begin()+k; ++c) res += isVowel(*c);
        int count=res;
        for(auto c = s.begin()+k; c<s.end(); ++c){
            count -= isVowel(*(c-k));
            count += isVowel(*c);
            res = max(res, count);
        }
        return res;
    }
};