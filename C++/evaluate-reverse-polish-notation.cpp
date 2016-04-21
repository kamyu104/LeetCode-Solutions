// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) {
            return 0;
        }
        stack<string> s;
        for (const auto& tok : tokens) {
            if (!is_operator(tok)) {
                s.emplace(tok);
            } else {
                auto&& y = stoi(s.top());
                s.pop();
                auto&& x = stoi(s.top());
                s.pop();
                if (tok[0] == '+') {
                    x += y;
                } else if (tok[0] == '-') {
                    x -= y;
                } else if (tok[0] == '*') {
                    x *= y;
                } else {
                    x /= y;
                }
                s.emplace(to_string(x));
            }
        }
        return stoi(s.top());
    }

private:
    bool is_operator(const string& op) {
        return op.length() == 1 && string("+-*/").find(op) != string::npos;
    }
};
