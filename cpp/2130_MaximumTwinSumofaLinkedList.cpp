/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        deque<int> val;
        while(head!=NULL){
            val.push_back(head->val);
            head=head->next;
        }
        int res=INT_MIN;
        int n=val.size();
        for(int i=0;i<n/2; ++i){
            res = max(res, val.front()+val.back());
            val.pop_back();
            val.pop_front();
        }
        return res;
    }
};