// Time:  O(nlogn)
// Space: O(n)

// binary search, longest increasing subsequence, lis
class Solution {
public:
    int minOperations(vector<int>& nums) {
        const auto& longest_non_increasing_subsequence = [](const auto& arr) {
            vector<int> result;
            for (const auto& x : arr) {
                auto it = upper_bound(begin(result), end(result), -x);
                if (it == end(result)) {
                    result.emplace_back(-x);
                } else {
                    *it = -x;
                }
            }
            return size(result);
        };

        return longest_non_increasing_subsequence(nums);
    }
};
