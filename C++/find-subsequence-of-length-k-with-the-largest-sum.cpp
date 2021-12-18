// Time:  O(n)
// Space: O(n)

// quick select solution
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> partition(begin(nums), end(nums));
        nth_element(begin(partition), begin(partition) + k - 1, end(partition), greater<int>());
        int cnt = count(begin(partition), begin(partition) + k, partition[k - 1]);
        vector<int> result;
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] > partition[k - 1] || (nums[i] == partition[k - 1] && --cnt >= 0)) {
                result.emplace_back(nums[i]);
            }
        }
        return result;
    }
};
