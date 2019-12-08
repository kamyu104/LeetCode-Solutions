// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.cbegin(), nums.cend());
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (check(nums, mid, threshold)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool check(const vector<int>& nums, int x, int threshold) {
        return accumulate(nums.cbegin(), nums.cend(), 0,
                          [&x](const auto& a, const auto& b) {
                              return a + (b - 1) / x + 1;
                          })
               <= threshold;
    }
};
