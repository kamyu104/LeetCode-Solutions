// Time:  O(nlogn + qlogn)
// Space: O(n)

// sort, binary search, prefix sum
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(begin(nums), end(nums));
        vector<long long> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<long long> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            const long long q = queries[i];
            const int j = distance(cbegin(nums), lower_bound(cbegin(nums), cend(nums), q));
            result[i] = (q * j - prefix[j]) + ((prefix.back() - prefix[j]) - q * (size(nums) - j));
        }
        return result;
    }
};
