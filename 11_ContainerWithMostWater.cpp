class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()==2)
            return min(height[1], height[0]);
        int maxA = 0, i=0, j=height.size()-1;
        while(i<j){
            int minH = min(height[i], height[j]);
            maxA = max(maxA, (j-i)*minH);
            while(i<j && height[i]<=minH){
                i++;
            }
            while(i<j && height[j]<=minH){
                j--;
            }
        }
        
        return maxA;
    }
};