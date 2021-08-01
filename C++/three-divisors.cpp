// Time:  O(sqrt(n))
// Space: O(1)

class Solution {
public:
    bool isThree(int n) {
        int cnt = 0;
        for (int i = 1; i <= n / i && cnt <= 3; ++i) {
            if (n % i == 0) {
                cnt += (i == n / i) ? 1 : 2;
            }
        }
        return cnt == 3;
    }
};
