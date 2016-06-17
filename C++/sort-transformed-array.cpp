// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> result;
        const auto f = [](int x, int a, int b, int c) {
            return a * x * x + b * x + c;
        };

        if (nums.empty()) {
            return result;
        }
        int left = 0, right = nums.size() - 1;
        if (a > 0) {
            while (left <= right) {
                if (f(nums[left], a, b, c) > f(nums[right], a, b, c)) {
                    result.emplace_back(f(nums[left++], a, b, c));
                } else {
                    result.emplace_back(f(nums[right--], a, b, c));
                }
            }
            reverse(result.begin(), result.end());
        } else {
            while (left <= right) {
                if (f(nums[left], a, b, c) < f(nums[right], a, b, c)) {
                    result.emplace_back(f(nums[left++], a, b, c));
                } else {
                    result.emplace_back(f(nums[right--], a, b, c));
                }
            }
        }
        return result;
    }
};
