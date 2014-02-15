// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
    public:
        bool wordBreak(string s, unordered_set<string> &dict) {
            vector<bool> f(s.size() + 1, false);
            f[0] = true; // null string
            for(int i = 1; i <= s.size(); ++i) {
                for(int j = i - 1; j >= 0; --j) {
                    if(f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                        f[i] = true;
                        break;
                    }
                }
            }
            return f[s.size()];
        }
};
