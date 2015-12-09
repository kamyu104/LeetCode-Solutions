// Time:  O(n)
// Space: O(k)

class Solution {
public:
    string removeDuplicateLetters(string s) {
        const int k = 26;
        unordered_map<char, int> cnts;
        unordered_set<char> visited;
        string res;
        stack<char> stk;
        for (const auto& c : s) {
            ++cnts[c];
        }
        for (int i = 0; i < s.size(); --cnts[s[i]], ++i) {
            if (!visited.count(s[i]) && (stk.empty() || stk.top() != s[i])) {
                while (!stk.empty() && stk.top() >= s[i] && cnts[stk.top()] > 0) {
                    visited.erase(stk.top());
                    stk.pop();
                }
                stk.emplace(s[i]);
                visited.emplace(s[i]);
            }
        }
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res; 
    }
};
