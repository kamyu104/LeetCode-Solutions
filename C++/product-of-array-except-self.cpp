// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        vector<int> left_product(nums.size());

        left_product[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            left_product[i] = left_product[i - 1] * nums[i - 1];
        }

        int right_product = 1;
        for (int j = nums.size() - 2; j >= 0; --j) {
            right_product *= nums[j + 1];
            left_product[j] = left_product[j] * right_product;
        }

        return left_product;
    }
};
