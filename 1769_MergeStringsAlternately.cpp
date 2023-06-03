class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string newS = "";
        int i=0;
        while(i<word1.length() || word2.length()){
            if(i<word1.length())
                newS += word1[i];
            
            if(i<word2.length())
                newS += word2[i];
            
            i++;
        }
        return newS;
    }
};