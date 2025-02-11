// Time:  O(d * n)
// Space: O(d)

// case works, math, freq table
class Solution {
public:
    long long countSubstrings(string s) {
        int64_t result = 0;
         vector<int> cnt;

        // digit 1, 2, 5
        for (int i = 0; i < size(s); ++i) {
            if (s[i] == '1' || s[i] == '2' || s[i] == '5') {
                result += i + 1;
            }
        }
        // digit 3, 6
        cnt.assign(3, 0);
        cnt[0] = 1;
        for (int i = 0, remain = 0; i < size(s); ++i) {
            remain = (remain + (s[i] - '0')) % 3;
            if (s[i] == '3' || s[i] == '6') {
                result += cnt[remain];
            }
            ++cnt[remain];
        }
        // digit 9
        cnt.assign(9, 0);
        cnt[0] = 1;
        for (int i = 0, remain = 0; i < size(s); ++i) {
            remain = (remain + (s[i] - '0')) % 9;
            if (s[i] == '9') {
                result += cnt[remain];
            }
            ++cnt[remain];
        }
        // digit 4
        for (int i = 0; i < size(s); ++i) {
            if (s[i] == '4') {
                ++result;
                if (i - 1 >= 0 && stoi(s.substr(i - 1, 2)) % 4 == 0) {
                    result += i;
                }
            }
        }
        // digit 8
        for (int i = 0; i < size(s); ++i) {
            if (s[i] == '8') {
                ++result;
                if (i - 1 >= 0 && stoi(s.substr(i - 1, 2)) % 8 == 0) {
                    ++result;
                }
                if (i - 2 >= 0 && stoi(s.substr(i - 2, 3)) % 8 == 0) {
                    result += i - 1;
                }
            }
        }
        // digit 7
        cnt.assign(7, 0);
        for (int i = 0, remain = 0, base = 1; i < size(s); ++i, base = (base * 10) % 7) {
            remain = (remain + base  * (s[(size(s) - 1) - i] - '0')) % 7;
            result += cnt[remain];
            if (s[(size(s) - 1) - i]  == '7') {
                ++result;
                ++cnt[remain];
            }
        }
        return result;
    }
};

// Time:  O(d * n)
// Space: O(d)
// case works, math, freq table
class Solution2 {
public:
    long long countSubstrings(string s) {
        int64_t result = 0;
        vector<int> cnt;

        // digit 4
        for (int i = 0; i < size(s); ++i) {
            if (s[i] == '4') {
                ++result;
                if (i - 1 >= 0 && stoi(s.substr(i - 1, 2)) % 4 == 0) {
                    result += i;
                }
            }
        }
        // digit 8
        for (int i = 0; i < size(s); ++i) {
            if (s[i] == '8') {
                ++result;
                if (i - 1 >= 0 && stoi(s.substr(i - 1, 2)) % 8 == 0) {
                    ++result;
                }
                if (i - 2 >= 0 && stoi(s.substr(i - 2, 3)) % 8 == 0) {
                    result += i - 1;
                }
            }
        }
        for (int d = 1; d <= 9; ++d) {
            if (d == 4 || d == 8) {
                continue;
            }
            cnt.assign(d, 0);
            for (int i = 0, remain = 0, base = 1; i < size(s); ++i, base = (base * 10) % d) {
                remain = (remain + base  * (s[(size(s) - 1) - i] - '0')) % d;
                result += cnt[remain];
                if (s[(size(s) - 1) - i] - '0' == d) {
                    ++result;
                    ++cnt[remain];
                }
            }
        }
        return result;
    }
};

// Time:  O(d^2 * n)
// Space: O(d^2)
// dp
class Solution3 {
public:
    long long countSubstrings(string s) {
        int64_t result = 0;
        vector<vector<int>> dp(10, vector<int>(10));
        for (int i = 1; i <= size(s); ++i) {
            vector<vector<int>> new_dp(10, vector<int>(10));
            const int x = s[i - 1] - '0';
            for (int d = 1; d <= 9; ++d) {
                ++new_dp[d][x % d];
                for (int r = 0; r < d; ++r) {
                    new_dp[d][(r * 10 + x) % d] += dp[d][r];
                }
            }
            dp = move(new_dp);
            result += dp[x][0];
        }
        return result;
    }
};
