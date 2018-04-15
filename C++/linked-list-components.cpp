// Time:  O(m + n), m is the number of G, n is the number of nodes
// Space: O(m)

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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> lookup(G.cbegin(), G.cend());
        ListNode dummy(-1);
        dummy.next = head;
        auto curr = &dummy;
        int result = 0;
        while (curr && curr->next) {
            if (!lookup.count(curr->val) && lookup.count(curr->next->val)) {
                ++result;
            }
            curr = curr->next;
        }
        return result;
    }
};
