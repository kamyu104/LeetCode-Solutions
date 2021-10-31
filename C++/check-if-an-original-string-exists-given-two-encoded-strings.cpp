// Time:  O(m * n * k), k is the max number of consecutive digits in s1 and s2
// Space: O(m * n * k)

// top-down dp (faster since accessing less states)
class Solution {
public:
    bool possiblyEquals(string s1, string s2) {
        vector<vector<unordered_map<int, bool>>> lookup(size(s1) + 1, vector<unordered_map<int, bool>>(size(s2) + 1));
        return memoization(s1, s2, 0, 0, 0, &lookup);
    }

private:
    int memoization(const string& s1, const string& s2, int i, int j, int k, vector<vector<unordered_map<int, bool>>> *lookup) {
        if (!(*lookup)[i][j].count(k)) {
            if (i == size(s1) && j == size(s2)) {
                (*lookup)[i][j][k] = (k == 0);
            } else if (i != size(s1) && isdigit(s1[i])) {
                (*lookup)[i][j][k] = false;
                int ni = i + 1;
                for (; ni < size(s1); ++ni) {
                    if (!isdigit(s1[ni])) {
                        break;
                    }
                }
                for (const auto& x : possible_numbers(s1.substr(i, ni - i))) {
                    if (memoization(s1, s2, ni, j, k + x, lookup)) {
                        (*lookup)[i][j][k] = true;
                        break;
                    }
                }
            } else if (j != size(s2) && isdigit(s2[j])) {
                (*lookup)[i][j][k] = false;
                int nj = j + 1;
                for (; nj < size(s2); ++nj) {
                    if (!isdigit(s2[nj])) {
                        break;
                    }
                }
                for (const auto& x : possible_numbers(s2.substr(j, nj - j))) {
                    if (memoization(s1, s2, i, nj, k - x, lookup)) {
                        (*lookup)[i][j][k] = true;
                        break;
                    }
                }
            } else if (k < 0) {
                (*lookup)[i][j][k] = (i != size(s1)) ? memoization(s1, s2, i + 1, j, k + 1, lookup) : false;
            } else if (k > 0) {
                (*lookup)[i][j][k] = (j != size(s2)) ? memoization(s1, s2, i, j + 1, k - 1, lookup) : false;
            } else {
                (*lookup)[i][j][k] = (i != size(s1) && j != size(s2) && s1[i] == s2[j]) ? memoization(s1, s2, i + 1, j + 1, 0, lookup) : false;
            }
        }
        return (*lookup)[i][j][k];
    }

    unordered_set<int> possible_numbers(const string& s) {  // Time: O(2^l), Space: O(2^l), l is the length of consecutive digits s
        vector<unordered_set<int>> dp(size(s));
        for (int i = 0; i < size(s); ++i) {
            for (int j = i, curr = 0, basis = 1; j >= 0; --j, basis *= 10) {
                curr += (s[j] - '0') * basis;
                if (s[j] == '0') {
                    continue;
                }
                if (j == 0) {
                    dp[i].emplace(curr);
                } else {
                    for (const auto& x : dp[j - 1]) {
                        dp[i].emplace(x + curr);
                    }
                }
            }
        }
        return dp.back();
    }
};

// Time:  O(m * n * k), k is the max number of consecutive digits in s1 and s2
// Space: O(m * n * k)
// top-down dp (faster since accessing less states)
class Solution2 {
public:
    bool possiblyEquals(string s1, string s2) {
        vector<vector<unordered_map<int, bool>>> lookup(size(s1) + 1, vector<unordered_map<int, bool>>(size(s2) + 1));
        return memoization(s1, s2, 0, 0, 0, &lookup);
    }

private:
    int memoization(const string& s1, const string& s2, int i, int j, int k, vector<vector<unordered_map<int, bool>>> *lookup) {
        if (!(*lookup)[i][j].count(k)) {
            if (i == size(s1) && j == size(s2)) {
                (*lookup)[i][j][k] = (k == 0);
            } else if (i != size(s1) && isdigit(s1[i])) {
                (*lookup)[i][j][k] = false;
                for (int ni = i + 1; ni <= size(s1); ++ni) {
                    if ((ni == size(s1) || s1[ni] != '0') && memoization(s1, s2, ni, j, k + stoi(s1.substr(i, ni - i)), lookup)) {
                        (*lookup)[i][j][k] = true;
                        break;
                    }
                    if (ni == size(s1) || !isdigit(s1[ni])) {
                        break;
                    }
                }
            } else if (j != size(s2) && isdigit(s2[j])) {
                (*lookup)[i][j][k] = false;
                for (int nj = j + 1; nj <= size(s2); ++nj) {
                    if ((nj == size(s2) || s2[nj] != '0') && memoization(s1, s2, i, nj, k - stoi(s2.substr(j, nj - j)), lookup)) {
                        (*lookup)[i][j][k] = true;
                        break;
                    }
                    if (nj == size(s2) || !isdigit(s2[nj])) {
                        break ;
                    }
                }
            } else if (k < 0) {
                (*lookup)[i][j][k] = (i != size(s1)) ? memoization(s1, s2, i + 1, j, k + 1, lookup) : false;
            } else if (k > 0) {
                (*lookup)[i][j][k] = (j != size(s2)) ? memoization(s1, s2, i, j + 1, k - 1, lookup) : false;
            } else {
                (*lookup)[i][j][k] = (i != size(s1) && j != size(s2) && s1[i] == s2[j]) ? memoization(s1, s2, i + 1, j + 1, 0, lookup) : false;
            }
        }
        return (*lookup)[i][j][k];
    }
};

// Time:  O(m * n * k), k is the max number of consecutive digits in s1 and s2
// Space: O(min(m, n) * k)
// bottom-up dp
class Solution3 {
public:
    bool possiblyEquals(string s1, string s2) {
        static const int MAX_DIGIT_LEN = 3;
        static const int w = 1 + MAX_DIGIT_LEN;

        if (size(s1) < size(s2)) {
            swap(s1, s2);
        }
        vector<vector<unordered_map<int, bool>>> dp(w, vector<unordered_map<int, bool>>(size(s2) + 1));
        dp[0][0][0] = true;
        for (int i = 0; i <= size(s1); ++i) {
            if (i >= 1) {
                dp[(i - 1) % w] = vector<unordered_map<int, bool>>(size(s2) + 1);
            }
            for (int j = 0; j <= size(s2); ++j) {
                for (const auto& [k, v] : dp[i % w][j]) {
                    if (!v) {
                        continue;
                    }
                    if (i != size(s1) && j != size(s2) && s1[i] == s2[j] && k == 0) {
                        dp[(i + 1) % w][j + 1][k] = true;
                    }
                    if (k <= 0 && i != size(s1)) {
                        if (isalpha(s1[i])) {
                            if (k) {
                                dp[(i + 1) % w][j][k + 1] = true;
                            }
                        } else if (s1[i] != '0') {
                            int curr = 0;
                            for (int ni = i; ni < size(s1) && isdigit(s1[ni]); ++ni) {
                                curr = curr * 10 + (s1[ni] - '0');
                                dp[(ni + 1) % w][j][k + curr] = true;
                            }
                        }
                    }
                    if (k >= 0 && j != size(s2)) {
                        if (isalpha(s2[j])) {
                            if (k) {
                                dp[i % w][j + 1][k - 1] = true;
                            }
                        } else if (s2[j] != '0') {
                            int curr = 0;
                            for (int nj = j; nj < size(s2) && isdigit(s2[nj]); ++nj) {
                                curr = curr * 10 + (s2[nj] - '0');
                                dp[i % w][nj + 1][k - curr] = true;
                            }
                        }
                    }
                }
            }
        }
        return dp[size(s1) % w][size(s2)][0];
    }
};
