class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0)
            return true;
        int i=0;
        for(char c : t){
            if(s[i]==c){
                i++;
            }
            if(i>s.length()-1){
                return true;
            }
        }
        return false;
    }
};