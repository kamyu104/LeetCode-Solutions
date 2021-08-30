// Time:  O(n) ~ O(n^2), O(n) on average
// Space: O(1)

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        nth_element(begin(nums), begin(nums) + k - 1, end(nums),
                    [](const auto& a, const auto& b) {
                        return size(a) == size(b) ? a > b : size(a) > size(b);
                    });
        return nums[k - 1];
    }
};
