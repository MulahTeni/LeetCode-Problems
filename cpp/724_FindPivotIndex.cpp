class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==1)  return 0;
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        for(int i = 1; i<nums.size(); i++)      left[i] += left[i-1] + nums[i-1];
        for(int i = nums.size()-2; i>=0; i--)   right[i] += right[i+1] + nums[i+1];
        for(int i=0; i<nums.size(); i++)        if(left[i]==right[i])   return i;
        return -1;
    }
};

// better memory solution

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rsum = accumulate(nums.begin(), nums.end(), 0);
        int lsum = 0;
        for(int i=0; i<nums.size(); ++i){
            rsum -= nums[i];
            if(rsum == lsum)    return i;
            lsum += nums[i];
        }
        return -1;
    }
};