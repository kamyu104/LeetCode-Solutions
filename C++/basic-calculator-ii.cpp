// Time:  O(n)
// Space: O(n)

// Support +, -, *, /.
class Solution {
public:
    int calculate(string s) {
        static const unordered_map<char, int> precedence = {{'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}};

        stack<int64_t> operands;
        stack<char> operators;
        int64_t operand = 0;
        for (int i = 0; i < size(s); ++i) {
            if (isdigit(s[i])) {
                operand = operand * 10 + s[i] - '0';
                if (i + 1 == size(s) || !isdigit(s[i + 1])) {
                    operands.emplace(operand);
                    operand = 0;
                }
            } else if (s[i] == '(') {
                operators.emplace(s[i]);
            } else if (s[i] == ')') {
                while (operators.top() != '(') {
                    compute(&operands, &operators);
                }
                operators.pop();
            } else if (precedence.count(s[i])) {
                while (!empty(operators) && precedence.count(operators.top()) && 
                       precedence.at(operators.top()) >= precedence.at(s[i])) {
                     compute(&operands, &operators);
                }
                operators.emplace(s[i]);
            }
        }
        while (!empty(operators)) {
            compute(&operands, &operators);
        }
        return operands.top();
    }

private:
    template<typename T>
    void compute(stack<T> *operands, stack<char> *operators) {
        const auto right = operands->top(); operands->pop();
        const auto left = operands->top(); operands->pop();
        const char op = operators->top(); operators->pop();
        if (op == '+') {
            operands->emplace(left + right);
        } else if (op == '-') {
            operands->emplace(left - right);
        } else if (op == '*') {
            operands->emplace(left * right);
        } else if (op == '/') {
            operands->emplace(left / right);
        }
    }
};

// Time:  O(n)
// Space: O(n)
// Support +, -, *, /.
class Solution2 {
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
