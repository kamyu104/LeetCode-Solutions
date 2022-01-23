// Time:  O(n)
// Space: O(n)

// freq table
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        vector<int> result;
        for (const auto& x : nums) {
            if (cnt[x] == 1 && !cnt.count(x - 1) && !cnt.count(x + 1)) {
                result.emplace_back(x);
            }
        }
        return result;
    }
};
