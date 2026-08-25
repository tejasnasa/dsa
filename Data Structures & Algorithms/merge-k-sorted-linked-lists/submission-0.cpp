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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> minheap;

        ListNode head(0);
        ListNode* iter = &head;

        for (auto node: lists) {
            if (node) minheap.push({node->val, node});
        }

        while (!minheap.empty()) {
            auto node = minheap.top();
            minheap.pop();

            iter->next = node.second;
            iter = iter->next;

            if (node.second->next) {
                minheap.push({node.second->next->val, node.second->next});
            }
        }

        iter->next = nullptr;

        return head.next;
    }
};
