// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        const auto result = distance(nums.begin(), max_element(nums.begin(),nums.end()));
        for (int i = 0; i < nums.size(); ++i) {
            if (i != result && 2 * nums[i] > nums[result]) {
                return -1;
            }
        }
        return result;
    }
};
