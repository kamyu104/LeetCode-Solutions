// Time:  O(n)
// Space: O(n)

class Solution {
public:
    long long maxProduct(string s) {
        const auto& P = manacher(s);
        queue<pair<int64_t, int64_t>> q;
        vector<int64_t> left = {0};
        for (int i = 0; i < size(s); ++i) {
            while (!empty(q) && q.front().second < i) {
                q.pop();
            }
            left.emplace_back(max(left.back(), empty(q) ? 1 : 1 + 2 * (i - q.front().first)));
            q.emplace(i, i + P[2 * i + 2] / 2);
        }
        q = queue<pair<int64_t, int64_t>>();
        int64_t result = 0, right = 0;
        for (int i = size(s) - 1; i >= 0; --i) {
            while (!empty(q) && q.front().second > i) {
                q.pop();
            }
            right = max(right, empty(q) ? 1 : 1 + 2 * (q.front().first - i));
            q.emplace(i, i - P[2 * i + 2] / 2);
            result = max(result, left[i] * right);
        }
        return result;
    }

private:
    vector<int> manacher(const string& s) {
        string T = preProcess(s);
        const int n = size(T);
        vector<int> P(n);
        int C = 0, R = 0;
        for (int i = 1; i < n - 1; ++i) {
            int i_mirror = 2 * C - i;
            P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                ++P[i];
            }
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        return P;
    }

    string preProcess(const string& s) {
        if (empty(s)) {
            return "^$";
        }
        string ret = "^";
        for (int i = 0; i < size(s); ++i) {
            ret += "#" + s.substr(i, 1);
        }
        ret += "#$";
        return ret;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    long long maxProduct(string s) {
        const auto& l1 = find_max_len(s);
        reverse(begin(s), end(s));
        const auto& l2 = find_max_len(s);
        int64_t result = 0;
        for (int i = 0; i < size(l1); ++i) {
            result = max(result, int64_t(l1[i]) * l2[size(l2) - 1 - i]);
        }
        return result;
    }

private:
    vector<int> find_max_len(const string& s) {
        const auto& P = manacher(s);
        vector<pair<int, int>> intervals;
        for (int i = 2; i < size(P) - 2; i += 2) {
            intervals.emplace_back((i - 2) / 2 - P[i] / 2, (i - 2) / 2 + P[i] / 2);
        }
        vector<int> dp(size(s));
        for (int i = size(intervals) - 1; i >= 0; --i) {
            dp[intervals[i].second] = intervals[i].second - intervals[i].first + 1;
        }
        for (int i = size(intervals) - 2; i >= 0; --i) {
            dp[i] = max(dp[i], dp[i + 1] - 2);
        }
        vector<int> result = {0};
        for (int i = 0; i < size(dp); ++i) {
            result.emplace_back(max(result.back(), dp[i]));
        }
        return result;
    }

    vector<int> manacher(const string& s) {
        string T = preProcess(s);
        const int n = size(T);
        vector<int> P(n);
        int C = 0, R = 0;
        for (int i = 1; i < n - 1; ++i) {
            int i_mirror = 2 * C - i;
            P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                ++P[i];
            }
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        return P;
    }

    string preProcess(const string& s) {
        if (empty(s)) {
            return "^$";
        }
        string ret = "^";
        for (int i = 0; i < size(s); ++i) {
            ret += "#" + s.substr(i, 1);
        }
        ret += "#$";
        return ret;
    }
};
