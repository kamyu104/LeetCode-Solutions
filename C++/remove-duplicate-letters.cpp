// Time:  O(n)
// Space: O(k), k is size of the alphabet

// vector solution, need to know size of the alphabet in advance (4ms)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        const int k = 26;
        vector<int> remaining(k);
        for (const auto& c : s) {
            ++remaining[c - 'a'];
        }

        vector<bool> in_stack(k);
        string stk;
        for (const auto& c : s) {
            if (!in_stack[c - 'a']) {
                while (!stk.empty() && stk.back() > c && remaining[stk.back() - 'a']) {
                    in_stack[stk.back() - 'a'] = false;
                    stk.pop_back();
                }
                stk.push_back(c);
                in_stack[c - 'a'] = true;
            }
            --remaining[c - 'a'];
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
        unordered_map<char, int> remaining;
        for (const auto& c : s) {
            ++remaining[c];
        }

        unordered_set<char> in_stack;
        string stk;
        for (const auto& c : s) {
            if (!in_stack.count(c)) {
                while (!stk.empty() && stk.back() > c && remaining[stk.back()]) {
                    in_stack.erase(stk.back());
                    stk.pop_back();
                }
                stk.push_back(c);
                in_stack.emplace(c);
            }
            --remaining[c];
        }
        return stk; 
    }
};
