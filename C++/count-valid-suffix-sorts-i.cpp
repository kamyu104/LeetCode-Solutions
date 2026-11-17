// Time:  O(n)
// Space: O(n)

// freq table
class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        for (const auto& x : target) {
            --cnt[x];
        }
        if (any_of(cbegin(cnt), cend(cnt), [](const auto& x) {
            return x.second != 0;
        })) {
            return 0;
        }
        int right = 0;
        for (; right + 1 < size(nums) && nums[right] == target[right]; ++right);
        int left = size(nums) - 1;
        for (; left - 1 >= 0 && target[left - 1] >= target[left]; --left);
        return max(right - left + 1, 0);
    }
};
