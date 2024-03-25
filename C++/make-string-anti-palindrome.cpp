// Time:  O(n + 26)
// Space: O(26)

// counting sort, greedy
class Solution {
public:
    string makeAntiPalindrome(string s) {
        vector<int> cnt(26);
        for (const auto& x : s) {
            ++cnt[x - 'a'];
        }
        if (ranges::max(cnt) > size(s) / 2) {
            return "-1";
        }
        string result(size(s), 0);
        for (int i = 0, j = 0; i < size(cnt); ++i) {
            for (int _ = 0; _ < cnt[i]; ++_) {
                result[j++] = 'a' + i;
            }
        }
        int l = 0;
        for (; l <= (size(s) / 2) / 2; ++l) {
            if (result[size(s) / 2 + l] != result[size(s) / 2 - 1]) {
                break;
            }
        }
        if (l) {
            for (int i = 0; i < cnt[result[size(s) / 2 - 1] - 'a'] - l; ++i) {
                swap(result[size(s) / 2 + i], result[size(s) / 2 + i + l]);
            }
        }
        return result;
    }
};

// Time:  O(n + 26)
// Space: O(26)
// counting sort, greedy, two pointers
class Solution2 {
public:
    string makeAntiPalindrome(string s) {
        vector<int> cnt(26);
        for (const auto& x : s) {
            ++cnt[x - 'a'];
        }
        if (ranges::max(cnt) > size(s) / 2) {
            return "-1";
        }
        string result(size(s), 0);
        for (int i = 0, j = 0; i < size(cnt); ++i) {
            for (int _ = 0; _ < cnt[i]; ++_) {
                result[j++] = 'a' + i;
            }
        }
        int left = size(s) / 2;
        int right = left + 1;
        for (; right < size(s) && result[right] == result[left]; ++right);
        for (; result[left] == result[(size(s) - 1) - left]; ++left, ++right) {
            swap(result[left], result[right]);
        }
        return result;
    }
};

// Time:  O(n * 26)
// Space: O(26)
// freq table, greedy
class Solution3 {
public:
    string makeAntiPalindrome(string s) {
        vector<int> cnt(26);
        for (const auto& x : s) {
            ++cnt[x - 'a'];
        }
        if (ranges::max(cnt) > size(s) / 2) {
            return "-1";
        }
        string result(size(s), 0);
        for (int i = 0; i < size(s) / 2; ++i) {
            int j = 0;
            for (; j < size(cnt); ++j) {
                if (cnt[j]) {
                    break;
                }
            }
            --cnt[j];
            result[i] = 'a' + j;
        }
        for (int i = size(s) / 2; i < size(s); ++i) {
            int j = 0;
            for (; j < size(cnt); ++j) {
                if (cnt[j] && result[(size(s) - 1) - i] != 'a' + j) {
                    break;
                }
            }
            --cnt[j];
            result[i] = 'a' + j;
        }
        return result;
    }
};
