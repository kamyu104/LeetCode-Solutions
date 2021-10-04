// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        string stk;
        vector<int> suffix(size(s) + 1);
        for (int i = size(suffix) - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + (s[i] == letter);
        }
        for (int i = 0; i < size(s); ++i) {
            while (!empty(stk) && stk.back() > s[i] && size(stk) + (size(s) - i) > k && (stk.back() != letter || repetition + 1 <= suffix[i])) {
                repetition += (stk.back() == letter); stk.pop_back();
            }
            if (size(stk) < min(k - (repetition - (s[i] == letter)), k)) {
                repetition -= (s[i] == letter);
                stk.push_back(s[i]);
            }
        }
        return stk;
    }
};
