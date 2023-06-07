class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        if (nums.size() < 2)
            return 0;
        int i=0, res=0, j= nums.size()-1;
        sort(nums.begin(), nums.end());
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum == k)    ++res, ++i, --j;
            else if(sum < k) i++;
            else    j--; 
        }

        return res;
    }
};