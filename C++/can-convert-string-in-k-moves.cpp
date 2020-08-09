// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> cnt(26);
        for (int i = 0; i < s.length(); ++i) {
            int diff = (cnt.size() + t[i] - s[i]) % cnt.size();
            if (diff && cnt[diff] * cnt.size() + diff > k) {
                return false;
            }
            ++cnt[diff];
        }
        return true;
    }
};
