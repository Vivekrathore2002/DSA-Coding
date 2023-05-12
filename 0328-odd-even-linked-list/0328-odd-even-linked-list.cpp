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
 //Code from solutions
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return NULL;
        ListNode* p=head;
        ListNode* q=head->next;
        ListNode* curr=head->next;
        while(q && q->next){
            p->next=p->next->next;
            p=p->next;
            q->next=q->next->next;
            q=q->next;
        }
        p->next=curr;
        return head;
    }
};