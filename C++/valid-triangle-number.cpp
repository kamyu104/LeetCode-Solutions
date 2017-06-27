// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 2 < nums.size(); ++i) {
            if (nums[i] == 0) {
                continue;
            }
            auto k = i + 2;
            for (int j = i + 1; j + 1 < nums.size(); ++j) {
                while (k < nums.size() && nums[i] + nums[j] > nums[k]) {
                    ++k;
                }
                result += k - j - 1;
            }
        }
        return result;
    }
};

