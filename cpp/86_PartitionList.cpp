/*
86. Partition List
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.


Example 1:

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:

Input: head = [2,1], x = 2
Output: [1,2]

*/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lessHead = new ListNode(0);
        ListNode *lessTail = lessHead;

        ListNode *greatHead = new ListNode(0);
        ListNode *greatTail = greatHead;

        while(head){
            int val = head->val;
            ListNode *newNode = new ListNode(val);
            if(val<x){
                lessTail->next = newNode;
                lessTail = lessTail->next;
            }else{
                greatTail->next = newNode;
                greatTail = greatTail->next;
            }
            head = head->next;
        }

        lessTail->next = greatHead->next;
        
        return lessHead->next;
    }
};