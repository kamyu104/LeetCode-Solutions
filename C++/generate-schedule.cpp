// Time:  O(n^2)
// Space: O(1)

// constructive algorithms
class Solution {
public:
    vector<vector<int>> generateSchedule(int n) {
        vector<vector<int>> result;
        if (n <= 4) {
            return result;
        }
        const auto& l = 1;
        if (n % 2 == 0) {
            for (int i = 0; i < n; i += 2) {
                result.push_back({i, i + l});
            }
            for (int i = 0; i < n; i += 2) {
                result.push_back({i + l, i});
            }
            for (int i = 1; i < n; i += 2) {
                result.push_back({i, (i + l) % n});
            }
            for (int i = 1; i < n; i += 2) {
                result.push_back({(i + l) % n, i});
            }
        } else {
            for (int i = 0; i < 2 * n; i += 2) {
                result.push_back({i % n, (i + l) % n});
            }
            for (int i = 0; i < 2 * n; i += 2) {
                result.push_back({(i + l) % n, i % n});
            }
        }
        for (int l = 2; l < (n + 1) / 2; ++l) {
            int j;
            j = result.back()[0] + 1;
            for (int i = j; i < j + n; ++i) {
                result.push_back({i % n, (i + l) % n});
            }
            j = ((result.back()[1] - 1) % n + n) % n;
            for (int i = j; i < j + n; ++i) {
                result.push_back({(i + l) % n, i % n});
            }
        }
        if (n % 2 == 0) {
            const auto& l = n / 2;
            const auto& j = ((result.back()[0] - 1) % n + n) % n;
            for (int i = j; i < j + n; ++i) {
                result.push_back({i % n, (i + l) % n});
            }
        }
        return result;
    }
};
