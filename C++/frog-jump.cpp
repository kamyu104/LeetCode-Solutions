// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < stones.size(); ++i) {
            lookup[stones[i]] = i;
        }

        vector<bool> dp(stones.size());
        dp[0] = true;
        for (int i = 0; i < stones.size(); ++i) {
            if (dp[i]) {
                for (const auto& k : {i - 1, i, i + 1}) {
                    const auto it = lookup.find(stones[i] + k);
                    if (it != lookup.end()) {
                        dp[it->second] = true;
                    }
                }
            }
        }
        return dp.back();
    }
};

