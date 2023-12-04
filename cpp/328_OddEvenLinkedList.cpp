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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)              return NULL;
        ListNode* evenH = head->next;
        ListNode* odd = head;
        for(ListNode* even=evenH; even!=NULL && even->next!=NULL; even=even->next){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
        }
        odd->next = evenH;
        return head;
    }
};