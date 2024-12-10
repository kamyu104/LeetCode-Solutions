// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        const int n = size(nums);
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = nums[(((i + nums[i]) % n) + n) % n];
        }
        return result;
    }
};
