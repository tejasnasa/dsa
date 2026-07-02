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
    bool hasCycle(ListNode* head) {
        if (!head) return false;
        
        ListNode* p = head;
        ListNode* q = head;
        int flag = 0;

        while (p->next && q->next) {
            p = p->next;
            if (flag) {
                q = q->next;
            }
            flag = !flag;

            if (p == q) {
                return true;
            }
        }

        return false;
    }
};
