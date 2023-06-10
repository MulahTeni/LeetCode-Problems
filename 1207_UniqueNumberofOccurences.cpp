class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> nums, nCount;
        bool res = true;
        for(int num : arr)  nums.count(num) ? ++nums[num] : nums[num]=1;
        for(auto m : nums)  nCount.count(m.second) ? res=false : nCount[m.second]=1;
        return res;
    }
};