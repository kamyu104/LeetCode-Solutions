// Time:  ctor:      O(1)
//        getRandom: O(n)
// Space: O(1)

// if the length is unknown without using extra space
class Solution {
public:
    Solution(ListNode* head) : head_(head), gen_(random_device()()) {
        
    }
    
    int getRandom() {
        auto reservoir = -1;
        auto n = 0;
        for (auto curr = head_; curr; curr = curr->next) {
            uniform_int_distribution<int> dist(0, n++);
            if (dist(gen_) == 0) {
                reservoir = curr->val;
            }
        }
        return reservoir;
    }

private:
    ListNode *head_;
    default_random_engine gen_;
};

// Time:  ctor:      O(n)
//        getRandom: O(1)
// Space: O(n)
// if the length is known with using extra space
class Solution2 {
public:
    Solution2(ListNode* head) : gen_(random_device()()) {
        for (; head; head = head->next) {
            nums_.emplace_back(head->val);
        }
    }
    
    int getRandom() {
        uniform_int_distribution<int> dist(0, size(nums_) - 1);
        return nums_[dist(gen_)];
    }

private:
    vector<int> nums_;
    default_random_engine gen_;
};
