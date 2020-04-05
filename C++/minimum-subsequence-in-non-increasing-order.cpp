// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int total = accumulate(cbegin(nums), cend(nums), 0), curr = 0;
        sort(begin(nums), end(nums), greater<int>());
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curr += nums[i];
            if (curr > total - curr) {
                result = i + 1;
                break;
            }
        }
        return vector<int>(cbegin(nums), cbegin(nums) + result);
    }
};
