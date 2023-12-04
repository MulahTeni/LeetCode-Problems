class Solution {
public:
    int compress(vector<char>& chars) {
        char b = chars[0];
        string s="";
        int count=0;
        for(char c: chars){
            if(b == c){
                count++;
            }else{
                if(count!=1){
                    s += b + to_string(count);
                }else{
                     s += b;
                }
                count=1;
                b = c;
            }
        }
        if(count!=1){
            s += b + to_string(count);
        }else{
            s += b;
        }
        chars.clear();
        for(char c : s){
            chars.push_back(c);
        }
        return s.length();
    }
};