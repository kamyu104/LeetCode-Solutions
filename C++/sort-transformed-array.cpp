// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        const auto f = [](int x, int a, int b, int c) {
            return a * x * x + b * x + c;
        };

        vector<int> result;
        if (nums.empty()) {
            return result;
        }

        int left = 0, right = nums.size() - 1;
        int d = a > 0 ? -1 : 1;
        while (left <= right) {
            if (d * f(nums[left], a, b, c) < d * f(nums[right], a, b, c)) {
                result.emplace_back(f(nums[left++], a, b, c));
            } else {
                result.emplace_back(f(nums[right--], a, b, c));
            }
        }
        if (d == -1) {
            reverse(result.begin(), result.end());
        }

        return result;
    }
};
