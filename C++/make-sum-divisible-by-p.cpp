// Time:  O(n)
// Space: O(p)

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int residue = 0;
        for (const auto& num : nums) {
            residue = (residue + num) % p;
        }
        if (!residue) {
            return 0;
        }
        int result = size(nums);
        unordered_map<int, int> lookup = {{0, -1}};
        for (int i = 0, curr = 0; i < size(nums); ++i) {
            curr = (curr + nums[i]) % p;
            lookup[curr] = i;
            if (lookup.count((curr - residue + p) % p)) {
                result = min(result, i - lookup[(curr - residue + p) % p]);
            }
        }
        return result < size(nums) ? result : -1;
    }
};
