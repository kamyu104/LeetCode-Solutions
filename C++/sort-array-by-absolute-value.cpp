// Time:  O(n + r)
// Space: O(n + r)

// sort
class Solution {
public:
    vector<int> sortByAbsoluteValue(vector<int>& nums) {
        int mx = 0;
        for (const auto& x : nums) {
            mx = max(mx, abs(x));
        }
        vector<vector<int>> lookup(mx + 1);
        for (const auto& x : nums) {
            lookup[abs(x)].emplace_back(x);
        }
        vector<int> result;
        result.reserve(size(nums));
        for (const auto& xs : lookup) {
            for (const auto& x : xs) {
                result.emplace_back(x);
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(1)
// sort
class Solution2 {
public:
    vector<int> sortByAbsoluteValue(vector<int>& nums) {
        ranges::sort(nums, [](const auto& a, const auto& b) {
            return abs(a) < abs(b);
        });
        return nums;
    }
};
