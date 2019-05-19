// Time:  O(2^n)
// Space: O(2^n)

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        unordered_set<int> dp = {0};
        const auto& S = accumulate(stones.cbegin(), stones.cend(), 0);
        for (const auto& stone : stones) {
            auto tmp(dp);
            for (const auto& i : dp) {
                tmp.emplace(i + stone);
            }
            dp = move(tmp);
        };
        auto result = numeric_limits<int>::max();
        for (const auto& i : dp) {
            result = min(result, abs(i - (S - i)));
        }
        return result;
    }
};
