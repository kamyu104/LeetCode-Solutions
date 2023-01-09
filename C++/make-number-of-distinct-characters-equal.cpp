// Time:  O(m + n + 26^2)
// Space: O(26)

// freq table
class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> cnt1(26);
        for (const auto& c : word1) {
            ++cnt1[c - 'a'];
        }
        vector<int> cnt2(26);
        for (const auto& c : word2) {
            ++cnt2[c - 'a'];
        }
        const auto& op = [](const auto& total, const auto& x) {
            return total + static_cast<int>(x != 0);
        };
        const int c1 = accumulate(cbegin(cnt1), cend(cnt1), 0, op);
        const int c2 = accumulate(cbegin(cnt2), cend(cnt2), 0, op);
        for (int i = 0; i < size(cnt1); ++i) {
            if (!cnt1[i]) {
                continue;
            }
            for (int j = 0; j < size(cnt2); ++j) {
                if (!cnt2[j]) {
                    continue;
                }
                if (i == j) {
                    if (c1 == c2) {
                        return true;
                    }
                } else {
                    int new_c1 = c1, new_c2 = c2;
                    if (cnt1[i] == 1) {
                        --new_c1;
                    }
                    if (cnt1[j] == 0) {
                        ++new_c1;
                    }
                    if (cnt2[j] == 1) {
                        --new_c2;
                    }
                    if (cnt2[i] == 0) {
                        ++new_c2;
                    }
                    if (new_c1 == new_c2) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
