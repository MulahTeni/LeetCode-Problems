class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> num1Map;
        for(int num : nums1)        num1Map.count(num) ? ++num1Map[num] : num1Map[num]=1;
        map<int, int> num2Map;
        for(int num : nums2)        num2Map.count(num) ? ++num2Map[num] : num2Map[num]=1;
        vector<vector<int>> l(2, vector<int>());
        for(auto mapV : num1Map)    if(!num2Map.count(mapV.first)) l[0].push_back(mapV.first);
        for(auto mapV : num2Map)    if(!num1Map.count(mapV.first)) l[1].push_back(mapV.first);
        return l;
    }
};