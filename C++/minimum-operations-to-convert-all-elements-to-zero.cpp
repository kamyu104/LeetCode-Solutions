// Time:  O(n)
// Space: O(n)

// greedy, mono stack
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        vector<int> stk = {0};
        for (const auto& x : nums) {
            while (!empty(stk) && stk.back() > x) {
                stk.pop_back();
            }
            if (stk.back() < x) {
                ++result;
                stk.emplace_back(x);
            }
        }
        return result;
    }
};
