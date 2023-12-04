class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = *max_element(candies.begin(), candies.end());
        vector<bool> tf;
        for(int i=0; i<candies.size(); i++){
            tf.push_back(candies[i]+extraCandies>=max);
		}
        return tf;
    }
};