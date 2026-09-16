// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> lookup;
        for (const auto& [i, x] : views::enumerate(nums)) {
            lookup[x].emplace_back(i);
        }
        int result = 0;
        for (const auto& [_, idxs] : lookup) {
            if (size(idxs) < 3) {
                continue;
            }
            bool ok = true;
            for (int i = 0, diff = idxs[size(idxs) - 1] - idxs[size(idxs) - 2]; i + 2 < size(idxs); ++i) {
                if (idxs[i + 1] - idxs[i] != diff) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ++result;
            }
        }
        return result;
    }
};
