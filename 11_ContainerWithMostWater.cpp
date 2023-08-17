class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()==2)  return min(height[1], height[0]);

        int maxA = 0, left_index = 0, right_index=height.size()-1;
        
        while(left_index<right_index){
            int minH = min(height[left_index], height[right_index]);
            maxA = max(maxA, (right_index-left_index)*minH);

            while(left_index<right_index && height[left_index]<=minH){
                ++left_index;
            }

            while(left_index<right_index && height[right_index]<=minH){
                --right_index;
            }
        }

        return maxA;
    }
};
