// Time:  O(n + k)
// Space: O(1)

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        auto n = 0;
        auto curr = root;
        while (curr) {
            curr = curr->next;
            n += 1;
        }
        auto width = n / k;
        auto remainder = n % k;

        vector<ListNode *> result;
        curr = root;
        for (int i = 0; i < k; ++i) {
            auto head = curr;
            for (int j = 0; curr &&
                 j < width - 1 + static_cast<int>(i < remainder); ++j) {
                curr = curr->next;
            }
            if (curr) {
                auto tail = curr;
                curr = curr->next;
                tail->next = nullptr;
            }
            result.emplace_back(head);
        }
        return result;
    }
};
