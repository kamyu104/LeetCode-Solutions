// Time:  O(n)
// Space: O(k), k is size of the alphabet

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> cnts;
        for (const auto& c : s) {
            ++cnts[c];
        }

        unordered_set<char> visited;
        string stk;
        for (const auto& c : s) {
            if (!visited.count(c) && (stk.empty() || stk.back() != c)) {
                while (!stk.empty() && stk.back() >= c && cnts[stk.back()] > 0) {
                    visited.erase(stk.back());
                    stk.pop_back();
                }
                stk.push_back(c);
                visited.emplace(c);
            }
            --cnts[c];
        }
        return stk; 
    }
};
