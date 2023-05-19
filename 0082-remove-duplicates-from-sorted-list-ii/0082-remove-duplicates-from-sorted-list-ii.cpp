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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* dummy = new ListNode();  // Create a dummy node
        dummy->next = head;
        ListNode* past = dummy;
        ListNode* present = head;
        ListNode* future = head->next;

        while (future != nullptr) {
            if (present->val == future->val) {
                while (future != nullptr && future->val == present->val) {
                    future = future->next;
                }
                past->next = future;
                present = future;
                if (future != nullptr) {
                    future = future->next;
                }
            } else {
                past = past->next;
                present = present->next;
                future = future->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};
