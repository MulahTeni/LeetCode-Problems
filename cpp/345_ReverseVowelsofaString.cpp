class Solution {
public:
    string reverseVowels(string s) {
        int start=0;
        int end=s.size()-1;
        while(start<end){
            while(start<end && s[start] != 'a' && s[start] != 'e' && s[start] != 'i' && s[start] != 'o' && s[start] != 'u' && s[start] != 'O' && s[start] != 'U' && s[start] != 'A' && s[start] != 'E' && s[start] != 'I'){
                start++;
            }
            while(start<end && s[end] != 'a' && s[end] != 'e' && s[end] != 'i' && s[end] != 'o' && s[end] != 'u' && s[end] != 'O' && s[end] != 'U' && s[end] != 'A' && s[end] != 'E' && s[end] != 'I'){
                end--;
            }
            swap(s[start++], s[end--]);
        }
        return s;
    }
};