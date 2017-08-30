// Time:  O(n)
// Space: O(p), p is the number of paths

class Solution {
public:
    int pathSum(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int result = 0;
        queue<node> q;
        node dummy(10);
        auto parent_ptr = &dummy;
        for (const auto& num : nums) {
            node child(num);
            while (!parent_ptr->isParent(child)) {
                result += parent_ptr->leaf ? parent_ptr->val : 0;
                parent_ptr = &q.front();
                q.pop();
            }
            parent_ptr->leaf = false;
            child.val += parent_ptr->val;
            q.emplace(move(child));
        }
        while (!q.empty()) {
            result += q.front().val;
            q.pop();
        }
        return result;
    }

private:
    struct node {
        int level, i, val;
        bool leaf;
        node(int n) : level(n / 100 - 1), i((n % 100) / 10 - 1), val(n % 10), leaf(true) {};
        inline bool isParent(const node& other) {
            return level == other.level - 1 && i == other.i / 2;
        };
    };
};
