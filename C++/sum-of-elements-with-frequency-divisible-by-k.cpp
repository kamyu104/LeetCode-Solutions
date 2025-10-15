// Time:  O(n + r)
// Space: O(r)

// freq table
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        const int mx = ranges::max(nums);
        vector<int> cnt(mx + 1);
        for (const auto& x : nums) {
            ++cnt[x];
        }
        return accumulate(cbegin(nums), cend(nums), 0, [&](const auto& accu, const auto& x) {
            return accu + (cnt[x] % k == 0 ? x : 0);
        });
    }
};

// Time:  O(n)
// Space: O(n)
// freq table
class Solution2 {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        return accumulate(cbegin(nums), cend(nums), 0, [&](const auto& accu, const auto& x) {
            return accu + (cnt[x] % k == 0 ? x : 0);
        });
    }
};
