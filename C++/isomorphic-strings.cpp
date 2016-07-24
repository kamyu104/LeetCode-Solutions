// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> s2t(256, 0), t2s(256, 0);
        for (int i = 0; i < s.length(); ++i) {
            if (s2t[s[i]] == 0 && t2s[t[i]] == 0) {
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            } else if (s2t[s[i]] != t[i]) {
                // Contradict mapping.
                return false;
            }
        }
        return true;
    }
};
