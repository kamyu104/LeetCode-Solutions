// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int countSubstrings(string s) {
        auto result = 0;
        for (const auto& max_len : manacher(s)) {
            result += (max_len + 1) / 2;
        }
        return result;
    }

private:
    vector<int> manacher(const string& s) {
        string T = preProcess(s);
        const int n = T.length();
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
        if (s.empty()) {
            return "^$";
        }
        string ret = "^";
        for (int i = 0; i < s.length(); ++i) {
            ret += "#" + s.substr(i, 1);
        }
        ret += "#$";
        return ret;
    }
};

