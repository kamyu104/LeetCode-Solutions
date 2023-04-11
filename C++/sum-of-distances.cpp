// Time:  O(n)
// Space: O(n)

// freq table, prefix sum
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> result(size(nums));
        unordered_map<int, long long> cnt1, left;
        for (int i = 0; i < size(nums); ++i) {
            result[i] += cnt1[nums[i]] * i - left[nums[i]];
            ++cnt1[nums[i]];
            left[nums[i]] += i;
        }
        unordered_map<int, long long> cnt2, right;
        for (int i = size(nums) - 1; i >= 0; --i) {
            result[i] += right[nums[i]] - cnt2[nums[i]] * i ;
            ++cnt2[nums[i]];
            right[nums[i]] += i;
        }
        return result;
    }
};
