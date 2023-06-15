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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)   return NULL;
        stack<int> vals;
        
        for(ListNode* tmp=head;tmp!=NULL;tmp=tmp->next)
            vals.push(tmp->val);
        for(ListNode* tmp=head;tmp!=NULL;tmp=tmp->next){
            tmp->val = vals.top();
            vals.pop();
        }
        return head;
    }
};