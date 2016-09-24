// Time:  O(n) ~ O(n^2)
// Space: O(n)

class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) {
            return false;
        }

        unordered_map<int, unordered_set<int>> last_jump_units;
        for (const auto& s: stones) {
            last_jump_units.emplace(s, {unordered_set<int>()});
        }
        last_jump_units[1].emplace(1);

        for (int i = 0; i + 1 < stones.size(); ++i) {
            for (const auto& j : last_jump_units[stones[i]]) {
                for (const auto& k : {j - 1, j, j + 1}) {
                    if (k > 0 && last_jump_units.count(stones[i] + k)) {
                        last_jump_units[stones[i] + k].emplace(k);
                    }
                }
            }
        }

        return !last_jump_units[stones.back()].empty();
    }
};
