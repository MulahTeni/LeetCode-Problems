class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int i=2, diff=abs(arr[1]-arr[0]);
        while(i<arr.size()){
            if(diff!=abs(arr[i]-arr[i-1]))  return false;
            ++i;
        }
        return true;
    }
};