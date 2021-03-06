/* 
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head==NULL||head->next==NULL)
            return head;
        ListNode* prevl = head;
        ListNode* l = prevl->next;
        
        while(l!=NULL)
        {
            if (l->val==prevl->val)
            {
                prevl->next = l->next; //delete the l-node
            }
            else
            {
                prevl = l;
            }
            l = l->next;
        }
        return head;
    }
};