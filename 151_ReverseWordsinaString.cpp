class Solution {
public:
    string reverseWords(string s) {
        string s2 = "";
        istringstream words(s);
        string word;
        while(words>>word){
            s2 = " "+ word + s2;
        }
        s2.erase(s2.begin());
        return s2;
    }
};