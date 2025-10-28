// Time:  O(n)
// Space: O(n)

// greedy, quick select
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> arr(size(nums));
        for (int i = 0; i < size(arr); ++i) {
            arr[i] = nums[i] * nums[i];
        }
        nth_element(begin(arr), begin(arr) + (size(nums) / 2), end(arr));
        return accumulate(cbegin(arr), cend(arr), 0ll) - 2 * accumulate(cbegin(arr), cbegin(arr) + (size(arr) / 2), 0ll);
    }
};

// Time:  O(nlogn)
// Space: O(n)
// greedy, sort
class Solution2 {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> arr(size(nums));
        for (int i = 0; i < size(arr); ++i) {
            arr[i] = nums[i] * nums[i];
        }
        sort(begin(arr), end(arr));
        return accumulate(cbegin(arr), cend(arr), 0ll) - 2 * accumulate(cbegin(arr), cbegin(arr) + (size(arr) / 2), 0ll);
    }
};
