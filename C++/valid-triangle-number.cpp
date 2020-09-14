// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int result = 0;
        sort(begin(nums), end(nums));
        for (int i = size(nums) - 1; i >= 2; --i) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    result += right - left;
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(1)
class Solution2 {
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
