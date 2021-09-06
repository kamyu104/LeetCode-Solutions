// Time:  O(n^3)
// Space: O(n)

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> lookup;
        lookup[nums.back()] = 1;
        for (int c = size(nums) - 2; c >= 2; --c) {
            for (int b = 1; b < c; ++b) {
                for (int a = 0; a < b; ++a) {
                    if (lookup.count(nums[a] + nums[b] + nums[c])) {
                        result += lookup[nums[a] + nums[b] + nums[c]];
                    }
                }
            }
            ++lookup[nums[c]];
        }
        return result;
    }
};
