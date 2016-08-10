// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : head_(head) {
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        auto reservoir = head_->val;
        auto n = 1;
        for (auto curr = head_->next; curr; curr = curr->next) {
            if (rand() % ++n == 0) {
                reservoir = curr->val;
            }
        }
        return reservoir;
    }

private:
    ListNode *head_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
 
