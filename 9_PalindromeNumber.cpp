9. Palindrome Number

Given an integer x, return true if x is a 
palindrome, and false otherwise.

 
Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


// with toString
class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int len = str.length();
        for(int i=0; i<str.length()/2; ++i){
            if(str[i] != str[len - i - 1]) return false;
        }
        return true;
    }
};

// loop
class Solution {
public:
    bool isPalindrome(int x) {
        long newNum = 0, copyX = x;
        while(copyX > 0){
            newNum *= 10;
            newNum += copyX % 10;
            if(newNum == 0) return false;
            copyX /= 10;
        }
        return newNum == x;
    }
};