// Time:  O(nlogn)
// Space: O(n)

// prefix sum, two pointers, sliding window, bst, binary search
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        static const int INF = numeric_limits<int>::max();

        vector<int> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int result = INF;
        multiset<int> bst;
        for (int i = 0; i < size(nums); ++i) {
            if (i - l + 1 >= 0) {
                bst.emplace(prefix[i - l + 1]);
            }
            if (i - r >= 0) {
                bst.erase(bst.find(prefix[i - r]));
            }
            const auto it = bst.lower_bound(prefix[i + 1]);
            if (it != begin(bst)) {
                result = min(result, prefix[i + 1] - *prev(it));
            }
        }
        return result != INF ? result : -1;
    }
};
