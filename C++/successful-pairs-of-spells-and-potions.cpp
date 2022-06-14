// Time:  O(mlogm + nlogm)
// Space: O(1)

// binary search
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(begin(potions), end(potions));
        vector<int> result;
        for (const auto& s: spells) {
            result.emplace_back(size(potions) - distance(cbegin(potions), lower_bound(cbegin(potions), cend(potions), ceil_divide(success, s))));
        }
        return result;
    }

private:
    int64_t ceil_divide(int64_t a, int64_t b) {
        return (a + b - 1) / b;
    }
};
