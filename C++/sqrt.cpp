// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        int sqrt(int x) {
            int left = 1;
            int right = x;
            int last_mid = 0;

            while(left <= right) {
                int mid = left + (right - left) / 2;

                if(x / mid > mid) {
                    left = mid + 1;
                    last_mid = mid;
                }
                else if (x / mid < mid) {
                    right = mid - 1;
                }
                else
                    return mid;
            }

            return last_mid;
        }
};
