// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string parseTernary(string expression) {
        if (expression.empty()) {
            return "";
        }

        string stack;
        for (int i = expression.length() - 1; i >= 0; --i) {
            auto c = expression[i];
            if (!stack.empty() && stack.back() == '?') {
                stack.pop_back();  // pop '?'
                auto first = stack.back(); stack.pop_back();
                stack.pop_back();  // pop ':'
                auto second = stack.back(); stack.pop_back();
    
                if (c == 'T') {
                    stack.push_back(first);
                } else {
                    stack.push_back(second);
                }
            } else {
                stack.push_back(c);
            }
        }
    
        return string(1, stack.back());
    }
};
