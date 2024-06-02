// Time:  O(n + 26)
// Space: O(n + 26)

// greedy, hash table, stack
class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> lookup(26);
        for (int i = 0; i < size(s); ++i) {
            if (s[i] != '*') {
                lookup[s[i] - 'a'].emplace_back(i);
                continue;
            }
            for (auto& stk : lookup) {
                if (empty(stk)) {
                    continue;
                }
                s[stk.back()] = '*';
                stk.pop_back();
                break;
            }
        }
        s.erase(remove(begin(s), end(s), '*'), end(s));
        return s;
    }
};
