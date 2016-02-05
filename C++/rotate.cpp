// Time:  O(n)
// Space: O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (!nums.empty()) {
            k %= nums.size();
            reverse(nums.begin(), nums.begin() + nums.size() - k);
            reverse(nums.begin() + nums.size() - k, nums.end());
            reverse(nums.begin(), nums.end());
        }
    }
};
