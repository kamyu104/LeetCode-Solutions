// Time:  O(n)		
// Space: O(n)

class Solution {
public:
    bool isValid(string s) {
        const  unordered_map<char, char> symbol_pair = {{')', '('},
                                                        {']', '['},
                                                        {'}', '{'}};
        stack<char> parentheses;
        for (const auto& c: s) {
            const auto& it = symbol_pair.find(c);
            if (it != symbol_pair.cend()) {
                if (parentheses.empty() ||
                    parentheses.top() != it->second) {
                    return false;
                }
                parentheses.pop();
            } else {
                parentheses.emplace(c);
            }
        }
        return parentheses.empty();
    }
};
