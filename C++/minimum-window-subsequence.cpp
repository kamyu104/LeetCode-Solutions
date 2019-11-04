// Time:  O(s * t)
// Space: O(s)

class Solution {
public:
    string minWindow(string S, string T) {
        vector<vector<int>> lookup(S.size() + 1, vector<int>(26, -1));
        vector<int> find_char_next_pos(26, -1);
        for (int i = S.length() - 1; i >= 0; --i) {
            find_char_next_pos[S[i] - 'a'] = i + 1;
            lookup[i] = find_char_next_pos;
        }
        
        int min_i = -1, min_len = numeric_limits<int>::max();
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] != T[0]) {
                continue;
            }
            int start = i;
            for (const auto& c : T) {
                start = lookup[start][c - 'a'];
                if (start == -1) {
                    break;
                }
            }
            if (start != -1) {
               if (start - i < min_len) {
                   min_i = i;
                   min_len = start - i;
               }
            }
        }
        return min_i != -1 ? S.substr(min_i, min_len) : "";
    }
};

// Time:  O(s * t)
// Space: O(s)
class Solution2 {
public:
    string minWindow(string S, string T) {
        vector<vector<int>> dp(2, vector<int>(S.length(), -1));
        for (int j = 0; j < S.length(); ++j) {
            if (S[j] == T[0]) {
                dp[0][j] = j;
            }
        }
                
        for (int i = 1; i < T.length(); ++i) {
            int prev = -1;
            dp[i % 2] = vector<int>(S.length(), -1);
            for (int j = 0; j < S.length(); ++j) {
                if (prev != -1 && S[j] == T[i]) {
                    dp[i % 2][j] = prev;
                }
                if (dp[(i - 1) % 2][j] != -1) {
                    prev = dp[(i - 1) % 2][j];
                }
            }
        }

        int start = 0, end = S.length();
        for (int j = 0; j < S.length(); ++j) {
            int i = dp[(T.length() - 1) % 2][j];
            if (i >= 0 && j - i < end - start) {
                tie(start, end) = make_pair(i, j);
            }
        }
        return end < S.length() ? S.substr(start, end - start + 1) : "";
    }
};
