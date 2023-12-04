class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0, i=0, j=0;
        while(i<nums.size()){
            if(nums[i]==0)  --k;
            if(k<0 && nums[j++]==0) ++k;
            ++i;
        }
        return i-j;
    }
};