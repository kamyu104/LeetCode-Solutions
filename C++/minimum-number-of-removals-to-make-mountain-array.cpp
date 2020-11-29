// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> left_lis_len(size(nums));
        vector<int> lis;
        for (int i = 0; i + 1 < size(nums); ++i) {
            auto it = lower_bound(begin(lis), end(lis), nums[i]);
            left_lis_len[i] = distance(begin(lis), it);
            if (it == end(lis)) {
                lis.emplace_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        lis.clear();
        int max_len = 0;
        for (int i = size(nums) - 1; i > 0; --i) {
            auto it = lower_bound(begin(lis), end(lis), nums[i]);
            max_len = max(max_len, left_lis_len[i] + int(distance(begin(lis), it)));
            if (it == end(lis)) {
                lis.emplace_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return size(nums) - (1 + max_len);
    }
};
