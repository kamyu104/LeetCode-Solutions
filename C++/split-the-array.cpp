// Time:  O(n)
// Space: O(n)

// freq table
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            if (++cnt[x] > 2) {
                return false;
            }
        }
        return true;
    }
};
