// Time:  O(n)
// Space: O(1)

// greedy solution
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int result = 0;
        unordered_set<int> lanes = {2};
        for (int i = 0; i + 1 < size(obstacles); ++i) {
            lanes.erase(obstacles[i + 1]);
            if (!empty(lanes)) {
                continue;
            }
            ++result;
            for (int j = 1; j <= 3; ++j) {
                if (j != obstacles[i] && j != obstacles[i + 1]) {
                    lanes.emplace(j);
                }
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// dp solution
class Solution2 {
public:
    int minSideJumps(vector<int>& obstacles) {
        static const int MAX_N = 5 * 1e5;
        static const int INF = (MAX_N - 1) + 1;

        array<int, 3> dp{1, 0, 1};
        for (const auto& i : obstacles) {
            if (i) {
                dp[i - 1] = INF;
            }
            for (int j = 0; j < 3; ++j) {
                if (j + 1 != i) {
                    dp[j] = min({dp[0] + (j != 0), dp[1] + (j != 1), dp[2] + (j != 2)});
                }
            }
        }
        return *min_element(cbegin(dp), cend(dp));
    }
};
