class Solution {
public:
    string removeStars(string s) {
        string res= "";
        for(char c : s) c=='*' ? res.pop_back() : res.push_back(c);
        return res;
    }
};