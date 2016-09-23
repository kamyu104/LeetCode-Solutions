// Time:  O(n) ~ O(n^2)
// Space: O(n)

class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) {
            return false;
        }

        unordered_map<int, unordered_set<int>> lookup;
        for (const auto& s: stones) {
            lookup.emplace(s, {unordered_set<int>()});
        }
        lookup[1].emplace(1);

        for (int i = 0; i + 1 < stones.size(); ++i) {
            for (const auto& j : lookup[stones[i]]) {
                for (const auto& k : {j - 1, j, j + 1}) {
                    if (k > 0 && lookup.count(stones[i] + k)) {
                        lookup[stones[i] + k].emplace(k);
                    }
                }
            }
        }

        return !lookup[stones.back()].empty();
    }
};
