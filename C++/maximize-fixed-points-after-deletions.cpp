// Time:  O(nlogn)
// Space: O(n)

// sort, binary search, longest increasing subsequence, lis
class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        const auto& longest_increasing_subsequence = [](const auto& arr) {
            vector<int> result;
            for (const auto& [_, x] : arr) {  // modified
                auto it = lower_bound(begin(result), end(result), x);
                if (it == end(result)) {
                    result.emplace_back(x);
                } else {
                    *it = x;
                }
            }
            return size(result);
        };

        vector<pair<int, int>> pairs;
        for (int i = 0; i < size(nums); ++i) {
            if (i - nums[i] >= 0) {
                pairs.emplace_back(i - nums[i], nums[i]);
            }
        }
        ranges::sort(pairs);
        return longest_increasing_subsequence(pairs);
    }
};
