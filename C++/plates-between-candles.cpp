// Time:  O(n + q)
// Space: O(n)

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> left(size(s));
        unordered_map<int, int> prefix;
        for (int i = 0, curr = -1, cnt = 0; i < size(s); ++i) {
            if (s[i] == '|') {
                curr = i;
                prefix[i] = ++cnt;
            }
            left[i] = curr;
        }
        vector<int> right(size(s));
        for (int i = size(s) - 1, curr = size(s), cnt = 0; i >= 0; --i) {
            if (s[i] == '|') {
                curr = i;
                ++cnt;
            }
            right[i] = curr;
        }
        vector<int> result;
        for (const auto& q : queries) {
            const int l = right[q[0]], r = left[q[1]];
            result.emplace_back(l < r ? (r - l + 1) - (prefix[r] - prefix[l] + 1) : 0);
        }
        return result;
    }
};
