// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        vector<int> dp((size(dist) - 1) + 1);  // dp[i]: (min time by i skips) * speed
        for (int i = 0; i < size(dist); ++i) {
            for (int j = size(dp) - 1; j >= 0; --j) {
                dp[j] = (i < size(dist) - 1) ? ceil(dp[j] + dist[i], speed) * speed : dp[j] + dist[i];
                if (j - 1 >= 0) {
                    dp[j] = min(dp[j], dp[j - 1] + dist[i]);
                }
            }
        }
        const int64_t target = int64_t(hoursBefore) * speed;
        for (int i = 0; i < size(dist); ++i) {
            if (dp[i] <= target) {
                return i;
            }
        }
        return -1;
    }

private:
    int ceil(int a, int b) {
        return (a + b - 1) / b;
    }
};
