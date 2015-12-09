// Time:  O(n)
// Space: O(k), k is size of the alphabet

// vector solution, need to know size of the alphabet in advace (4ms)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        const int k = 26;
        vector<int> cnts(k);
        for (const auto& c : s) {
            ++cnts[c - 'a'];
        }

        vector<bool> visited(k);
        string stk;
        for (const auto& c : s) {
            if (!visited[c - 'a'] && (stk.empty() || stk.back() != c)) {
                while (!stk.empty() && stk.back() >= c && cnts[stk.back() - 'a'] > 0) {
                    visited[stk.back() - 'a'] = false;
                    stk.pop_back();
                }
                stk.push_back(c);
                visited[c - 'a'] = true;
            }
            --cnts[c - 'a'];
        }
        return stk; 
    }
};

// Time:  O(n)
// Space: O(k), k is size of the alphabet
// hash solution, no need to know size of the alphabet in advance (16ms)
class Solution2 {
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
