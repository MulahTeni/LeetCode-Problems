class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<string, int> word;
        string s="";
        int count=0, len=grid[0].size();
        for(int i=0; i<len; i++){
            s="";
            for(int j=0; j<len; j++)    s += " "+ to_string(grid[i][j]);
            word.count(s) ? ++word[s] : word[s]=1;
        }
        for(int i=0; i<len; i++){
            s="";
            for(int j=0; j<len; j++)    s += " "+ to_string(grid[j][i]);
            if(word.count(s))   count += word[s];
        }
        return count;
    }
};