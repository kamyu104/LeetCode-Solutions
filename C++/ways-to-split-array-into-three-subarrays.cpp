// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        static const int MOD = 1e9 + 7;
        
        vector<int> prefix(1);
        for (const auto& x : nums) {
            prefix.emplace_back(prefix.back() + x);
        }

        int result = 0, left = 0, right = 0;
        for (int i = 0; i < size(nums); ++i) {
            left = max(left, i + 1);
            while (left + 1 < size(nums) && prefix[i + 1] > prefix[left + 1] - prefix[i + 1]) {
                ++left;
            }
            right = max(right, left);
            while (right + 1 < size(nums) && prefix[right + 1] - prefix[i + 1] <= prefix.back() - prefix[right + 1]) {
                ++right;
            }
            result = (result + (right - left)) % MOD;
        }
        return result;
    }
};
