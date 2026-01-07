// Time:  O(n)
// Space: O(n)

// freq table, two pointers
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        static const int INF = numeric_limits<int>::max();

        int result = INF;
        unordered_map<int, int> cnt;
        for (int right = 0, left = 0, curr = 0; right < size(nums); ++right) {
            if (++cnt[nums[right]] == 1) {
                curr += nums[right];
            }
            for (; curr >= k; ++left) {
                result = min(result, right - left + 1);
                if (cnt[nums[left]]-- == 1) {
                    curr -= nums[left];
                }
            }
        }
        return result != INF ? result : -1;
    }
};
