// Time:  O(n)
// Space: O(n)

// Support +, -, *, /.
class Solution {
public:
    int calculate(string s) {
        stack<int64_t> operands;
        stack<char> operators;
        string operand;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (isdigit(s[i])) {
                operand.push_back(s[i]);
                if (i == 0 || !isdigit(s[i - 1])) {
                    reverse(operand.begin(), operand.end());
                    operands.emplace(stol(operand));
                    operand.clear();
                }
            } else if (s[i] == ')' || s[i] == '*' ||
                       s[i] == '/') {
                operators.emplace(s[i]);
            } else if (s[i] == '+' || s[i] == '-') {
                while (!operators.empty() && (operators.top() == '*' ||
                       operators.top() == '/')) {
                     compute(operands, operators);
                }
                operators.emplace(s[i]);
            } else if (s[i] == '(') {
                // operators at least one element, i.e. ')'.
                while (operators.top() != ')') {
                    compute(operands, operators);
                }
                operators.pop();
            }
        }
        while (!operators.empty()) {
            compute(operands, operators);
        }
        return operands.top();
    }

    void compute(stack<int64_t>& operands, stack<char>& operators) {
        const int64_t left = operands.top();
        operands.pop();
        const int64_t right = operands.top();
        operands.pop();
        const char op = operators.top();
        operators.pop();
        if (op == '+') {
            operands.emplace(left + right);
        } else if (op == '-') {
            operands.emplace(left - right);
        } else if (op == '*') {
            operands.emplace(left * right);
        } else if (op == '/') {
            operands.emplace(left / right);
        }
    }
};
