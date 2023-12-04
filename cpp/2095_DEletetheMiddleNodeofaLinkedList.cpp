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

// Better Runtime
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)    return NULL;
        ListNode *tmp1=head, *tmp2=head->next->next;
        while(tmp2!=NULL && tmp2->next!=NULL){
            tmp1=tmp1->next;
            tmp2=tmp2->next->next;
        }
        tmp1->next = tmp1->next->next;
        return head;

    }
};

// Better Memory
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)    return NULL;
        ListNode* tmp = head;
        int n=0;
        while(tmp!=NULL){
            ++n;
            tmp = tmp->next;
        }
        tmp = head;
        for(int i=0; i<n/2-1; ++i){
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        return head;


    }
};