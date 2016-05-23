// Time:  O(9 * 2^9)
// Space: O(9 * 2^9)

// DP solution.
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
        for (int used = 0; used < dp.size(); ++used) {
            const auto number = number_of_key(used);
            if (number > n) {
                continue;
            }
            for (int i = 0; i < 9; ++i) {
                if (!contain(used, i)) {
                    continue;
                }
                keys[number - 1] += dp[used][i];

                const auto x1 = i / 3;
                const auto y1 = i % 3;
                for (int j = 0; j < 9; ++j) {
                    if (contain(used, j)) {
                        continue;
                    }
                    const auto x2 = j / 3;
                    const auto y2 = j % 3;
                    if (((x1 == x2 && abs(y1 - y2) == 2) ||
                         (y1 == y2 && abs(x1 - x2) == 2) ||
                         (abs(x1 - x2) == 2 && abs(y1 - y2) == 2)) &&
                         !(contain(used, convert((x1 + x2) / 2, (y1 + y2) / 2)))) {
                             continue;
                    }
                    dp[merge(used, j)][j] += dp[used][i];
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
        int number = 0;
        for (; i; i &= i - 1) {
            ++number;
        }
        return number;
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
// Backtracking solution.
class Solution2 {
public:
    int numberOfPatterns(int m, int n) {
        int number = 0;
        // 1, 3, 5, 7
        number += 4 * numberOfPatternsHelper(m, n, 1, merge(0, 0), 0);
        // 2, 4, 6, 8
        number += 4 * numberOfPatternsHelper(m, n, 1, merge(0, 1), 1);
        // 5
        number += numberOfPatternsHelper(m, n, 1, merge(0, 4), 4);
        return number;
    }
private:
    int numberOfPatternsHelper(int m, int n, int level, int used, int i) {
        int number = 0;
        if (level > n) {
            return number;
        }
        if (level >= m) {
            ++number;
        }

        const auto x1 = i / 3;
        const auto y1 = i % 3;
        for (int j = 0; j < 9; ++j) {
            if (contain(used, j)) {
                continue;
            }
            const auto x2 = j / 3;
            const auto y2 = j % 3;
            if (((x1 == x2 && abs(y1 - y2) == 2) ||
                 (y1 == y2 && abs(x1 - x2) == 2) ||
                 (abs(x1 - x2) == 2 && abs(y1 - y2) == 2)) &&
                 !(contain(used, convert((x1 + x2) / 2, (y1 + y2) / 2)))) {
                     continue;
            }
            number += numberOfPatternsHelper(m, n, level + 1, merge(used, j), j);
        }
        return number;
    }

private:
    inline int merge(int i, int j) {
        return i | (1 << j);
    }

    inline bool contain(int i, int j) {
        return i & (1 << j);
    }

    inline int convert(int i, int j) {
        return 3 * i + j;
    }
};
