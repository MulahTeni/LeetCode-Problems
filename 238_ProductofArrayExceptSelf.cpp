class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        for(int i=0, j=0, mul=1; i<nums.size(); j++){
            if(i!=j){
                mul *= nums[j];
            }
            if(j==nums.size()-1){
                res.push_back(mul);
                j=-1;
                i++;
                mul = 1;
            }
        }
        return res;
    }
};
// Time Limit Exceeded

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        res[0]=1;
        for(int i=1; i<nums.size(); i++){
            res[i] = nums[i-1] * res[i-1];
        }
        int mul=1;
        for(int i=nums.size()-2; i>-1; i--){
            mul *= nums[i+1];
            res[i] *= mul;
        }
        return res;
    }
}
// left and right