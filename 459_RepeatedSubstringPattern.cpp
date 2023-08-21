/*

459. Repeated Substring Pattern

Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

 

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.


Example 2:

Input: s = "aba"
Output: false


Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.

*/


// Solution 1

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ans = "";
        for(auto c : s){
            ans += c;
            int mul = s.length() / ans.length();
            string check = ans;
            while(--mul){
                check += ans;
            }
            if(check == s && ans != s)    return true;
        }
        return false;
    }
};class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        if (t.substr(1, t.size() - 2).find(s) != -1) return true;
        return false;
    }
};

// Solution 2

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        if (t.substr(1, t.size() - 2).find(s) != -1) return true;
        return false;
    }
};