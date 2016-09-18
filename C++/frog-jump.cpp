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
                for (const auto& j : findStones(stones, lookup, i)) {
                    dp[j] = true;
                }
            }
        }
        return dp.back();
    }

private:
    vector<int> findNextStones(const vector<int>& stones,
                               const unordered_map<int, int>& lookup,
                               int i) {
        vector<int> next_stones;
        if (i == 0) {
            if (stones[1] == stones[0] + 1) {
                next_stones.emplace_back(1);
            }
        } else {
            for (const auto& k : {i - 1, i, i + 1}) {
                const auto it = lookup.find(stones[i] + k);
                if (it != lookup.end()) {
                    next_stones.emplace_back(it->second);
                }
            }
        }
        return next_stones;
    }
};
