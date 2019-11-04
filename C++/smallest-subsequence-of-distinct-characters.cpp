// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string smallestSubsequence(string text) {
        const int k = 26;
        vector<int> count(k);
        for (const auto& c : text) {
            ++count[c - 'a'];
        }

        vector<bool> lookup(k);
        string stk;
        for (const auto& c : text) {
            if (!lookup[c - 'a']) {
                while (!stk.empty() && stk.back() > c &&
                       count[stk.back() - 'a']) {
                    lookup[stk.back() - 'a'] = false;
                    stk.pop_back();
                }
                stk.push_back(c);
                lookup[c - 'a'] = true;
            }
            --count[c - 'a'];
        }
        return stk; 
    }
};
