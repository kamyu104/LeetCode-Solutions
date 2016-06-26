// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (mid >= num / mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left == num / left && num % left == 0;
    }
};
