// Time:  O(n)
// Space: O(n)

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double left = *min_element(nums.begin(), nums.end());
        double delta = numeric_limits<double>::max();
        while (delta > 1e-5) {
            delta = getDelta(left, nums, k);
            left += delta;
        }
        return left;
    }

private:
    double getDelta(double avg, const vector<int>& nums, int k) {
        vector<double> accu(nums.size() + 1);
        int minval_pos = -1;
        double delta = 0.0;
        for (int i = 0; i < nums.size(); ++i) {
            accu[i + 1] = nums[i] + accu[i] - avg;
            if (i >= k - 1) {
                if (minval_pos == -1 || accu[i - k + 1] < accu[minval_pos]) {
                    minval_pos = i - k + 1;
                }
                if (accu[i+1] - accu[minval_pos] >= 0) {
                    delta = max(delta, (accu[i + 1] - accu[minval_pos]) / (i + 1 - minval_pos));
                }
            }
        }
        return delta;
    }
};


// Time:  O(nlogm), m is (max_val - min_val)
// Space: O(1)
class Solution2 {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double left = *min_element(nums.begin(), nums.end());
        double right = *max_element(nums.begin(), nums.end());
        while (right - left > 1e-5) {
            double mid = left + (right - left) / 2;
            if (isMidLargerOrEqualToTarget(mid, nums, k)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }

private:
    bool isMidLargerOrEqualToTarget(double mid, const vector<int>& nums, int k) {
        double sum = 0, prev = 0, min_sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i] - mid;
        }
        if (sum > 0) {
            return false;
        }
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - mid;
            prev += nums[i - k] - mid;
            min_sum = min(prev, min_sum);
            if (sum > min_sum) {
                return false;
            }
        }
        return true;  
    }
};