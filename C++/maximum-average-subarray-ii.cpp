// Time:  O(nlog(max_val - min_val))
// Space: O(1)

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double left = *min_element(nums.begin(), nums.end());
        double right = *max_element(nums.begin(), nums.end());
        while (abs(left - right) > 0.00001) {
            double mid = left + (right - left) / 2;
            if (!check(nums, mid, k)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }

private:
    bool check(const vector<int>& nums, double mid, int k) {
        double sum = 0, prev = 0, min_sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i] - mid;
        }
        if (sum >= 0) {
            return true;
        }
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - mid;
            prev += nums[i - k] - mid;
            min_sum = min(prev, min_sum);
            if (sum >= min_sum) {
                return true;
            }
        }
        return true;
    }
};

