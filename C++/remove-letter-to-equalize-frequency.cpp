// Time:  O(n)
// Space: O(1)

// freq table, edge cases
class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> cnt(26);
        for (const auto& c : word) {
            ++cnt[c - 'a'];
        }
        unordered_map<int, int> cnt2;
        for (const auto& c : cnt) {
            if (c) {
                ++cnt2[c];
            }
        }
        if (size(cnt2) > 2) {
            return false;
        }
        if (size(cnt2) == 1) {
            return cbegin(cnt2)->first == 1 || cbegin(cnt2)->second == 1;
        }
        int a = cbegin(cnt2)->first;
        int b = next(cbegin(cnt2))->first;
        if (a > b) {
            swap(a, b);
        }
        return (a == 1 && cnt2[a] == 1) || (a + 1 == b && cnt2[b] == 1);
    }
};

// Time:  O(26 * n)
// Space: O(1)
// brute force, freq table
class Solution2 {
public:
    bool equalFrequency(string word) {
        vector<int> cnt(26);
        for (const auto& c : word) {
            ++cnt[c - 'a'];
        }
        for (const auto& c : word) {
            --cnt[c - 'a'];
            int i = 0;
            for (int prev = 0; i < size(cnt); ++i) {
                if (!cnt[i]) {
                    continue;
                }
                if (prev && prev != cnt[i]) {
                    break;
                }
                prev = cnt[i];
            }
            if (i == size(cnt)) {
                return true;
            }
            ++cnt[c - 'a'];
        }
        return false;
    }
};
