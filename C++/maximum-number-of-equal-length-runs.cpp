// Time:  O(n)
// Space: O(sqrt(n))

// freq table
class Solution {
public:
    int maxSameLengthRuns(string s) {
        unordered_map<int, int> cnt;
        for (int i = 0, l = 0; i < size(s); ++i) {
            ++l;
            if (i + 1 == size(s) || s[i + 1] != s[i]) {
                ++cnt[l];
                l = 0;
            }
        }
        return max_element(cbegin(cnt), cend(cnt), [](const auto& a, const auto& b) {
            return a.second < b.second;
        })->second;
    }
};

// Time:  O(n)
// Space: O(n)
// freq table
class Solution2 {
public:
    int maxSameLengthRuns(string s) {
        vector<int> cnt(size(s) + 1);
        for (int i = 0, l = 0; i < size(s); ++i) {
            ++l;
            if (i + 1 == size(s) || s[i + 1] != s[i]) {
                ++cnt[l];
                l = 0;
            }
        }
        return ranges::max(cnt);
    }
};
