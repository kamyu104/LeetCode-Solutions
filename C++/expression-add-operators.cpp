// Time:  O(4^n)
// Space: O(n)

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        vector<string> expr;
        int val = 0;
        string val_str;
        for (int i = 0; i < num.length(); ++i) {
            val = val * 10 + num[i] - '0';
            val_str.push_back(num[i]);
            // Avoid overflow and "00...".
            if (to_string(val) != val_str) {
                break;
            }
            expr.emplace_back(val_str);
            addOperatorsDFS(num, target, i + 1, 0, val, &expr, &result);
            expr.pop_back();
        }
        return result;
    }

    void addOperatorsDFS(const string& num, const int& target, const int& pos,
                         const int& operand1, const int& operand2, vector<string> *expr,
                         vector<string> *result) {
        if (pos == num.length()) {
            if (operand1 + operand2 == target) {
                result->emplace_back(move(join(*expr)));
            }
            return;
        }
    
        int val = 0;
        string val_str;
        for (int i = pos; i < num.length(); ++i) {
            val = val * 10 + num[i] - '0';
            val_str.push_back(num[i]);
            // Avoid overflow and "00...".
            if (to_string(val) != val_str) {
                break;
            }

            // Case '+':
            expr->emplace_back("+" + val_str);
            addOperatorsDFS(num, target, i + 1, operand1 + operand2, val, expr, result);
            expr->pop_back();

            // Case '-':
            expr->emplace_back("-" + val_str);
            addOperatorsDFS(num, target, i + 1, operand1 + operand2, -val, expr, result);
            expr->pop_back();
    
            // Case '*':
            expr->emplace_back("*" + val_str);
            addOperatorsDFS(num, target, i + 1, operand1, operand2 * val, expr, result);
            expr->pop_back();
        }
    }
    
    string join(const vector<string>& expr) {
        ostringstream stream;
        copy(expr.cbegin(), expr.cend(), ostream_iterator<string>(stream));
        return stream.str();
    }
};
