class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0, j=0, del=1;
        while(i<nums.size()){
            if(nums[i]==0)  --del;
            if(del<0 && nums[j++]==0) ++del;
            ++i;
        }
        return i-j-1;
    }
};