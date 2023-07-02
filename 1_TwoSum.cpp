class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> map1;
        vector<int> res;
        for(int i=0; i<nums.size(); ++i){
            if(map1.count(target-nums[i])>0){
                res.push_back(map1[target-nums[i]]);
                res.push_back(i);
                return res;
            }else map1[nums[i]] = i;
        }
        return res;
    }
};