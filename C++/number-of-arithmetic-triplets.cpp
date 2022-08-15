// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> lookup(cbegin(nums), cend(nums));
        return accumulate(cbegin(nums), cend(nums), 0, [&](const auto& total, const auto&x) {
            return total + lookup.count(x - diff) * lookup.count(x - 2 * diff);
        });
    }
};

// Time:  O(n)
// Space: O(n)
// dp
class Solution2 {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int result = 0;
        unordered_map<int, int> cnt1, cnt2;
        for (const auto& x : nums) {
            result += cnt2[x - diff];
            cnt2[x] += cnt1[x - diff];
            ++cnt1[x];
        }
        return result;
    }
};
