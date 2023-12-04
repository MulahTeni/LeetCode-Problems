class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = 0;
        for(int i=0; i<k; ++i){
            res += nums[i];
        }
        double sum=res;
        for(int i=k, j=0; i<nums.size(); ++i){
            sum += nums[i] - nums[j++];
            if(sum>res) res = sum;
        }
        return res/k;
    }
};