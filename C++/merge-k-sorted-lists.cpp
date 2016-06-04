// Time:  O(n * logk)
// Space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Merge two by two solution.
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return nullptr;
        }

        int left = 0, right = lists.size() - 1;
        while (right > 0) {
            if (left >= right) {
                left = 0;
            } else {
                lists[left] = mergeTwoLists(lists[left], lists[right]);
                ++left;
                --right;
            }
        }
        return lists[0];
    }
    
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy = ListNode(0);
        auto *curr = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;

        return dummy.next;
    }
};


// Time:  O(n * logk)
// Space: O(logk)
// Divide and Conquer solution.
class Solution2 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }

private:
    ListNode *mergeKListsHelper(const vector<ListNode *> &lists, int begin, int end) {
        if (begin > end) {
            return nullptr;
        }
        if (begin == end) {
            return lists[begin];
        }
        return mergeTwoLists(mergeKListsHelper(lists, begin, (begin + end) / 2),
                             mergeKListsHelper(lists, (begin + end) / 2 + 1, end));
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy = ListNode(0);
        auto *curr = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;

        return dummy.next;
    }
};


// Time:  O(n * logk)
// Space: O(k)
// Heap solution.
class Solution3 {
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
