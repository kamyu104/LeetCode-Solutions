// Time:  O(nlogn), m is the max of nums
// Space: O(1)

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        const auto& check = [&nums, &maxOperations](int x) {
            return accumulate(cbegin(nums), cend(nums), 0,
                              [&x](int total, int a) {
                                  return total + ((a + x - 1) / x - 1);
                              }) <= maxOperations;
        };
        int left = 1, right = *max_element(cbegin(nums), cend(nums));
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
