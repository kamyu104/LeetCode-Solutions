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
        string res;
        for (const auto& c : s) {
            if (!visited.count(c) && (res.empty() || res.back() != c)) {
                while (!res.empty() && res.back() >= c && cnts[res.back()] > 0) {
                    visited.erase(res.back());
                    res.pop_back();
                }
                res.push_back(c);
                visited.emplace(c);
            }
            --cnts[c];
        }
        return res; 
    }
};
