// Time:  O(n)
// Space: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (auto& num : nums) {
            if (num) {
                swap(nums[pos++], num);
            }
        }
    }
};

class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (const auto& num : nums) {
            if (num) {
                nums[pos++] = num;
            }
        }
        fill(next(nums.begin(), pos), nums.end(), 0);
    }
};
