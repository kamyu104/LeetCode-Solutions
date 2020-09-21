// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {  // find the largest right s.t. k > missingCount(nums, x)
            const auto& mid = left + (right - left) / 2;
            if (!check(nums, k, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return nums[right] + (k - missingCount(nums, right));
    }
    
private:
    int missingCount(const vector<int>& nums, int x) {
        return (nums[x] - nums[0] + 1) - (x - 0 + 1);
    }
    
    bool check(const vector<int>& nums, int k, int x) {
        return k > missingCount(nums, x);
    }
};
