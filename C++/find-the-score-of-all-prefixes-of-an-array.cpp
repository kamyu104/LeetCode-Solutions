// Time:  O(n)
// Space: O(1)

// prefix sum
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> result(size(nums));
        for (int i = 0, curr = 0; i < size(nums); ++i) {
            curr = max(curr, nums[i]);
            result[i] = (i - 1 >= 0 ? result[i - 1] : 0) + nums[i] + curr;
        }
        return result;
    }
};
