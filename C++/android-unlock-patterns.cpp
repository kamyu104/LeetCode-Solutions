// Time:  O(9 * 2^9)
// Space: O(9 * 2^9)

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        // dp[i][j]: i is the set of the numbers in binary presentation,
        //           d[i][j] is the number of ways ending with the number j.
        vector<vector<int>> dp(1 << 9 , vector<int>(9, 0));
        for (int i = 0; i < 9; ++i) {
            dp[merge(0, i)][i] = 1;
        }

        vector<int> keys(9, 0);
        for (int i = 0; i < dp.size(); ++i) {
            const auto count = number_of_key(i);
            if (count > n) {
                continue;
            }
            for (int j = 0; j < 9; ++j) {
                if (!contain(i, j)) {
                    continue;
                }
                keys[count - 1] += dp[i][j];

                const auto x1 = j / 3;
                const auto y1 = j % 3;
                for (int k = 0; k < 9; ++k) {
                    if (contain(i, k)) {
                        continue;
                    }
                    const auto x2 = k / 3;
                    const auto y2 = k % 3;
                    if (((x1 == x2 && abs(y1 - y2) == 2) ||
                         (y1 == y2 && abs(x1 - x2) == 2) ||
                         (abs(x1 - x2) == 2 && abs(y1 - y2) == 2)) &&
                         !(contain(i, convert((x1 + x2) / 2, (y1 + y2) / 2)))) {
                             continue;
                    }
                    dp[merge(i, k)][k] += dp[i][j];
                }
            }
        }
        int res = 0;
        for (int i = m - 1; i < n; ++i) {
            res += keys[i];
        }
        return res;
    }

private:
    inline int merge(int i, int j) {
        return i | (1 << j);
    }

    inline int number_of_key(int i) {
        int count = 0;
        for (; i; i &= i - 1) {
            ++count;
        }
        return count;
    }

    inline bool contain(int i, int j) {
        return i & (1 << j);
    }

    inline int convert(int i, int j) {
        return 3 * i + j;
    }
};

// Time:  O(9!)
// Space: O(9)
class Solution2 {
public:
    int numberOfPatterns(int m, int n) {
        int count = 0;
        bool visited[9] = {false};
        // 1, 3, 7, 9
        numberOfPatternsHelper(m, n, 0, 0, 1, visited, &count);
        // 2, 4, 6, 8
        numberOfPatternsHelper(m, n, 0, 1, 1, visited, &count);
        count *= 4;
        // 5
        numberOfPatternsHelper(m, n, 1, 1, 1, visited, &count);
        return count;
    }

private:
    const vector<vector<int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1},
        {2, 1}, {2, -1}, {-2, -1}, {-2, 1},
        {1, 2}, {-1, 2}, {1, -2}, {-1, -2}
    };

    void numberOfPatternsHelper(int m, int n, int i, int j, int level,
                                bool visited[], int *count) {
        if (level > n) {
            return;
        }

        if (level >= m) {
            ++(*count);
        }

        visited[convert(i, j)] = true;

        for (const auto& direction : directions) {
            auto x = i + direction[0];
            auto y = j + direction[1];
            if (valid(x, y)) {
                if (!visited[convert(x, y)]) {
                    numberOfPatternsHelper(m, n, x, y, level + 1, visited, count);
                } else {
                    x += direction[0];
                    y += direction[1];
                    if (valid(x, y) && !visited[convert(x, y)]) {
                        numberOfPatternsHelper(m, n, x, y, level + 1, visited, count);
                    }
                }
            }
        }

        visited[convert(i, j)] = false;
    }

    inline int convert(int i, int j) {
        return 3 * i + j;
    }

    inline bool valid(int i, int j) {
        return i >= 0 && i < 3 && j >= 0 && j < 3;
    }
};
