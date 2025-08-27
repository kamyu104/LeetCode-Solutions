// Time:  O(nlogn + mlogm)
// Space: O(n)

// sort, dp, two pointers
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        static const int INF = numeric_limits<int>::max();

        vector<pair<int, int>> x_d;
        x_d.emplace_back(0, 0);
        for (int i = 0; i < size(robots); ++i) {
            x_d.emplace_back(robots[i], distance[i]);
        }
        x_d.emplace_back(INF, 0);
        sort(begin(x_d), end(x_d), [](const auto& a, const auto& b) {
          return a.first < b.first;
        });
        sort(begin(walls), end(walls));
        int left0 = 0, left1 = 0, right = 0, curr = 0;
        vector<int> dp(2), new_dp(2);
        for (int i = 1; i + 1 < size(x_d); ++i) {
            for (; curr < size(walls) && walls[curr] < x_d[i].first; ++curr);
            const auto& r = min(x_d[i].first + x_d[i].second, x_d[i + 1].first - 1);
            for (; right < size(walls) && walls[right] <= r; ++right);
            new_dp[1] = max(dp[0], dp[1]) + (right - curr);
            if (curr < size(walls) && walls[curr] == x_d[i].first) {
                ++curr;
            }
            const auto& l0 = max(x_d[i].first - x_d[i].second, x_d[i - 1].first + 1);
            for (; left0 < size(walls) && walls[left0] < l0; ++left0);
            const auto& l1 = max(
                min(x_d[i - 1].first + x_d[i - 1].second, x_d[i].first - 1) + 1,
                max(x_d[i].first - x_d[i].second, x_d[i - 1].first + 1)
            );
            for (; left1 < size(walls) && walls[left1] < l1; ++left1);
            new_dp[0] = max(dp[0] + (curr - left0), dp[1] + (curr - left1));
            swap(dp, new_dp);
        }
        return max(dp[0], dp[1]);
    }
};
