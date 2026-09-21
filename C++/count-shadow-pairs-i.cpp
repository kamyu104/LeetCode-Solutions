// Time:  O(n)
// Space: O(n)

// freq table, mono stack
class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int64_t result = 0;
        vector<int> stk;
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            while (!empty(stk) && stk.back() > x) {
                --cnt[stk.back()];
                stk.pop_back();
            }
            result += size(stk) - cnt[x];
            stk.emplace_back(x);
            ++cnt[x];
        }
        return result;
    }
};
