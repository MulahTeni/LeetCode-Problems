/*
658. Find K Closest Elements
Medium
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array.
The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b


Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]


Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
*/

// Solution 1

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> ppq;

        for(int num: arr){
            ppq.push(make_pair(abs(x - num), num));
            if(ppq.size()>k) ppq.pop();
        }
        vector<int> res;
        while(!ppq.empty() && res.size()<k){
            auto p = ppq.top();
            res.push_back(p.second);
            ppq.pop();
        }
        sort(res.begin(), res.begin()+k);
        return res;
    }
};

// Solution 2
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size()==k)   return arr;
        int left_index =  0;
        int right_index = arr.size()-1;
        while(right_index - left_index != k){

            if(abs(x - arr[left_index]) < abs(x - arr[right_index]))
                --right_index;
            else if(abs(x - arr[left_index]) > abs(x - arr[right_index]))
                ++left_index;
            else
                --right_index;
        }
        if(abs(x - arr[left_index]) < abs(x - arr[right_index]))
            --right_index;
        else if(abs(x - arr[left_index]) > abs(x - arr[right_index]))
            ++left_index;
        else
            --right_index;
        return vector<int>(arr.begin()+left_index, arr.begin()+right_index+1);
    }
};
