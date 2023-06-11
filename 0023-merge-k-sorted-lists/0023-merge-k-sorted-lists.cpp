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

//  https://www.youtube.com/watch?v=0_PSq3j8GrY&ab_channel=CodewithAlisha
// using min heap

// class Solution {
// public:
// struct mycmp{
//     bool operator() (ListNode* a,ListNode* b)
//     {
//         return a->val > b->val;
//     }
// };
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<ListNode* ,vector<ListNode*>,mycmp>pq;
//         for(ListNode* x:lists)
//         {
//             if(pq) pq.push(x);
//         }
//         ListNOde* head=NULL;
//         ListNode* tail = NULL;
//         while(!pq.empty())
//         {
//             ListNode* x=pq.top();
//             pq.top();
//             if(head==NULL)
//             {
//                 head-x;
//                 tail = x;
//             }
//             else
//             {
//                 tail->next = x;
//                 tail = x;
//             }
//             if(x_>next) pq.push(x->next);
//         }
//         return head;
//     }
// };

class Solution {
public:
    struct mycmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, mycmp> pq;
        for (ListNode* x : lists) {
            if (x) pq.push(x);
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while (!pq.empty()) {
            ListNode* x = pq.top();
            pq.pop();

            if (head == NULL) {
                head = x;
                tail = x;
            } else {
                tail->next = x;
                tail = x;
            }

            if (x->next) pq.push(x->next);
        }

        return head;
    }
};
