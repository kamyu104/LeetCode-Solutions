// Time:  O(n)
// Space: O(1)

// graph, prefix sum
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        vector<int> result(size(nums));
        result[0] = nums[0];
        for (int i = 0; i + 1 < size(nums); ++i) {
            result[i + 1] = max(result[i], nums[i + 1]);
        }
        for (int i = size(nums) - 1, mn = numeric_limits<int>::max(); i >= 0; --i) {
            if (result[i] > mn) {
                result[i] = result[i + 1];
            }
            mn = min(mn, nums[i]);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// graph, prefix sum
class Solution2 {
public:
    vector<int> maxValue(vector<int>& nums) {
        vector<int> suffix(size(nums) + 1, numeric_limits<int>::max());
        for (int i = size(nums) - 1; i >= 0; --i) {
            suffix[i] = min(suffix[i + 1], nums[i]);
        }
        vector<int> result(size(nums));
        for (int right = 0, left = 0, mx = 0; right < size(nums); ++right) {
            mx = max(mx, nums[right]);
            if (mx > suffix[right + 1]) {
                continue;
            }
            for (; left <= right; ++left) {
                result[left] = mx;
            }
            
        }
        return result;
    }
};
