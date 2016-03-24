// Time:  O(n * logk)
// Space: O(k)

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        auto *cur = &dummy;

        struct Compare {
            bool operator() (const ListNode *a, const ListNode *b) {
                return a->val > b->val;
            }
        };

        // Use min heap to keep the smallest node of each list
        priority_queue<ListNode *, vector<ListNode *>, Compare> min_heap;
        for (const auto& n : lists) {
            if (n) {
                min_heap.emplace(n);
            }
        }

        while (!min_heap.empty()) {
            // Get min of k lists.
            auto *node = min_heap.top();
            min_heap.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next) {
                min_heap.emplace(node->next);
            }
        }

        return dummy.next;
    }
};


// Time:  O(n * logk)
// Space: O(k)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution2 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }

private:
    ListNode *mergeKLists(const vector<ListNode *> &lists, int begin, int end) {
        if (begin > end) {
            return nullptr;
        }
        if (begin == end) {
            return lists[begin];
        }
        return mergeTwoLists(mergeKLists(lists, begin, (begin + end) / 2),
                             mergeKLists(lists, (begin + end) / 2 + 1, end));
    }

    ListNode *mergeTwoLists(ListNode *left, ListNode *right) {
        ListNode dummy(0);
        auto *p = &dummy;
        for (; left && right; p = p->next) {
            if(left->val < right->val) {
                p->next = left;
                left = left->next;
            } else {
                p->next = right;
                right = right->next;
            }
        }
        if (left) {
            p->next = left;
        } else {
            p->next = right;
        }
        return dummy.next;
    }
};

