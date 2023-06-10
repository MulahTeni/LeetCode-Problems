class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length())  return false;
        for(char c : word1) if(!(word2.find(c)!=std::string::npos)) return false;
        map<char, int> c1, c2;
        for(int i=0; i<word1.length(); i++){
            c1.count(word1[i]) ? ++c1[word1[i]] : c1[word1[i]] = 1;
            c2.count(word2[i]) ? ++c2[word2[i]] : c2[word2[i]] = 1;
        }
        for(auto m1 : c1)
            for(auto m2 : c2)
                if(m1.second==m2.second){ 
                    c2[m2.first]=0; 
                    break;
                }
        for(auto m : c2)    if(m.second!=0) return false;
        return true;
    }
};