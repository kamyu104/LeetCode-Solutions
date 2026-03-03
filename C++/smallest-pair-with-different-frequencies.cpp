// Time:  O(n)
// Space: O(n)

// freq table
class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        static const int INF = numeric_limits<int>::max();

        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        const auto& x = ranges::min(nums);
        int mn = INF;
        for (const auto& y : nums) {
            if (cnt[y] != cnt[x]) {
                mn = min(mn, y);
            }
        }
        return mn != INF ? vector<int>{x, mn} : vector<int>{-1, -1};
    }
};
