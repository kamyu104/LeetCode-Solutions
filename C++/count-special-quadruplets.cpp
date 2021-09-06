// Time:  O(n^3)
// Space: O(n)

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> lookup;
        lookup[nums.back()] = 1;
        for (int c = size(nums) - 2; c >= 2; --c) {
            for (int b = 1; b < c; ++b) {
                for (int a = 0; a < b; ++a) {
                    if (lookup.count(nums[a] + nums[b] + nums[c])) {
                        result += lookup[nums[a] + nums[b] + nums[c]];
                    }
                }
            }
            ++lookup[nums[c]];
        }
        return result;
    }
};

// Time:  O(n^2) ~ O(n^4)
// Space: O(n^2)
class Solution2 {
public:
    int countQuadruplets(vector<int>& nums) {
        int result = 0;
        unordered_map<int, unordered_set<int>> lookup;
        for (int d = size(nums) - 1; d >= 3; --d) {
            for (int c = 2; c < d; ++c) {
                lookup[nums[d] - nums[c]].emplace(c);
            }
        }
        for (int b = 1; b < size(nums) - 2; ++b) {
            for (int a = 0; a < b; ++a) {
                result += accumulate(cbegin(lookup[nums[a] + nums[b]]), cend(lookup[nums[a] + nums[b]]), 0,
                                     [&b](const auto&total, const auto& x) {
                                         return b < x ? total + 1 : total;
                                     });
            }
        }
        return result;
    }
};
