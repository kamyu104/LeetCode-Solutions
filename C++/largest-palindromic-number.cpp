// Time:  O(n)
// Space: O(1)

// freq table, greedy
class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> cnt(10);
        for (const auto& c : num) {
            ++cnt[c - '0'];
        }
        string result;
        for (char c = '9'; c >= '0'; --c) {
            if (cnt[c - '0'] / 2 == 0 || (c == '0' && empty(result))) {
                continue;
            }
            result.insert(end(result), cnt[c - '0'] / 2, c);
        }
        const int l = size(result);
        for (char c = '9'; c >= '0'; --c) {
            if (cnt[c - '0'] % 2) {
                result.push_back(c);
                break;
            }
        }
        for (int i = l - 1; i >= 0; --i) {
            result.push_back(result[i]);
        }
        return !empty(result) ? result : "0";
    }
};
