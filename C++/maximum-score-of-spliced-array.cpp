// Time:  O(n)
// Space: O(1)

// greedy, kadane's algorithm
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        const auto& modified_kadane = [](const auto& a, const auto& b) {
            int result = 0, curr = 0;
            for (int i = 0; i < size(a); ++i) {
                curr = max(curr + (b[i] - a[i]), 0);
                result = max(result, curr);
            }
            return accumulate(cbegin(a), cend(a), 0) + result;
        };

        return max(modified_kadane(nums1, nums2), modified_kadane(nums2, nums1));
    }
};
