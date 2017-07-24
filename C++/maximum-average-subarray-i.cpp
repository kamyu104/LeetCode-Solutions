// Time:  O(n)
// Space: O(1)

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        double result = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i-k];
            result = max(result, sum);
        }
        return result / k;
    }
};

