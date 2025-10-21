// Time:  O(26 * n)
// Space: O(26)

// freq table, greedy
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        const auto& nxt = [](auto& cnt, int x) {
            for (int i = (x - 'a') + 1; i < size(cnt); ++i) {
                if (!cnt[i]) {
                    continue;
                }
                return static_cast<char>('a' + i);
            }
            return ' ';
        };

        vector<int> cnt(26);
        for (const auto& x : s) {
            ++cnt[x - 'a'];
        }
        vector<int> tmp(cnt);
        int j = -1;
        for (int i = 0; i < size(target); ++i) {
            const auto& y = nxt(tmp, target[i]);
            if (y != ' ') {
                j = i;
            }
            if (!tmp[target[i] - 'a']) {
                break;
            }
            --tmp[target[i] - 'a'];
        }
        string result;
        if (j == -1) {
            return result;
        }
        for (int i = 0; i < j; ++i) {
            result.push_back(target[i]);
            --cnt[target[i] - 'a'];
        }
        const auto& y = nxt(cnt, target[j]);
        result.push_back(y);
        --cnt[y - 'a'];
        for (int i = 0; i < size(cnt); ++i) {
            for (; cnt[i]; --cnt[i]) {
                result.push_back('a' + i);
            }
        }
        return result;
    }
};
