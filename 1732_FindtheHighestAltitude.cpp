class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxG=0;
        for(int i=0, sum=0; i<gain.size(); i++){
            sum += gain[i];
            maxG = max(sum, maxG);
        }
        return maxG;
    }
};