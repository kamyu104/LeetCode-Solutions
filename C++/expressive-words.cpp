// Time:  O(n + s), n is the sum of all word lengths, s is the length of S
// Space: O(l + s)

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int result = 0;
        const auto& R = RLE(S);
        for (const auto& word : words) {
            const auto& R2 = RLE(word);
            if (R.key != R2.key) {
                continue;
            }
            int i;
            for (i = 0; i < R.counts.size(); ++i) {
               const auto& c1 = R.counts[i];
               const auto& c2 = R2.counts[i];
               if (c1 < max(c2, 3) && c1 != c2) {
                   break;
               }
            }
            if (i == R.counts.size()) {
                ++result;
            }
        }
        return result;
    }

private:
    struct RLE {
        string key;
        vector<int> counts;
        RLE(const string& s) {
            int prev = -1;
            for (int i = 0; i < s.length(); ++i) {
                if (i == s.length() - 1 || s[i] != s[i + 1]) {
                    key.push_back(s[i]);
                    counts.emplace_back(i - prev);
                    prev = i;
                }
            }
        }
    };
};
