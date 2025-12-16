// Time:  O(n)
// Space: O(1)

// quick select
class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        nth_element(begin(nums), begin(nums) + (k - 1), end(nums));
        const auto& total1 = accumulate(cbegin(nums), cbegin(nums) + k, 0);
        nth_element(begin(nums), begin(nums) + (k - 1), end(nums), greater<int>());
        const auto& total2 = accumulate(cbegin(nums), cbegin(nums) + k, 0);
        return abs(total1 - total2);
    }
};

// Time:  O(nlogn)
// Space: O(1)
// sort
class Solution2 {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        const auto& total1 = accumulate(cbegin(nums), cbegin(nums) + k, 0);
        const auto& total2 = accumulate(cbegin(nums) + (size(nums) - k), cend(nums), 0);
        return abs(total1 - total2);
    }
};
