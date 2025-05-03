// Time:  O(26 * n)
// Space: O(26)

// freq table, counting sort, greedy, combinatorics
class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int> cnt(26);
        for (int i = 0; i < size(s) / 2; ++i) {
            ++cnt[s[i] - 'a'];
        }
        int total = 0, count = 1, remain = 0;
        int i;
        for (i = size(cnt) - 1; i >= 0; --i) {
            for (int c = 1; c <= cnt[i]; ++c) {
                ++total;
                count = count * total / c;
                if (count >= k) {
                    remain = cnt[i] - c;
                    break;
                }
            }
            if (count >= k) {
                break;
            }
        }
        if (count < k) {
            return "";
        }
        string result(size(s), 0);
        int l = 0;
        for (int j = 0; j <= i; ++j) {
            const char x = 'a' + j;
            const int c = j != i ? cnt[j] : remain;
            for (int _ = 0; _ < c; ++_) {
                --cnt[j];
                result[l++] = x;
            }
        }
        while (total) {
            for (int j = i; j < size(cnt); ++j) {
                if (!cnt[j]) {
                    continue;
                }
                const auto new_count = static_cast<int64_t>(count) * cnt[j] / total;
                if (new_count < k) {
                    k -= new_count;
                    continue;
                }
                count = new_count;
                --cnt[j];
                --total;
                result[l++] = 'a' + j;
                break;
            }
        }
        if (size(s) % 2) {
            result[l++] = s[size(s) / 2];
        }
        for (int i = l - 1 - size(s) % 2; i >= 0; --i) {
            result[l++] = result[i];
        }
        return result;
    }
};
