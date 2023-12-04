class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> big;
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};