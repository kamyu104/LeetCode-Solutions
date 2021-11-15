// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        static const int K = 3;

        unordered_map<char, int> cnt1;
        for (const auto& c : word1) {
            ++cnt1[c];
        }
        unordered_map<char, int> cnt2;
        for (const auto& c : word2) {
            ++cnt2[c];
        }
        for (const auto& [k, v] : cnt1) {
            if (abs(cnt2[k] - v) > K) {
                return false;
            }
        }
        for (const auto& [k, v] : cnt2) {
            if (abs(cnt1[k] - v) > K) {
                return false;
            }
        }
        return true;
    }
};
