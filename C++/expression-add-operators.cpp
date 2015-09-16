// Time:  O(3^n)
// Space: O(n)

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        vector<string> expr;
        addOperatorsDFS(num, target, 0, 0, 0, &expr, &result);
        return result;
    }

    bool addOperatorsDFS(const string& s, const int& target, const int& pos,
                         const int& operand1, const int& operand2, vector<string> *expr,
                         vector<string> *result) {
        // Base Case 1
        if (pos == s.length()) {
            if (operand1 + operand2 == target) {
                string e;
                for (int i = 0; i < expr->size(); ++i) {
                    if (i == 0 && (*expr)[i] == "+") {  // Skip '+' at the beginning of the string.
                        continue;
                    }
                    e.append((*expr)[i]);
                }
                result->emplace_back(move(e));
                return true;
            }
            return false;
        }
    
        int num = 0;
        string num_str;
        for (int i = pos; i < s.length(); ++i) {
            num_str += s[i];
            // Check if the value exceeds the max of INT.
            if (num_str.size() == to_string(numeric_limits<int>::max()).size() &&
                num_str > to_string(numeric_limits<int>::max())) {
                break;
            }
            
            num = num * 10 + s[i] - '0';

            // Case '+':
            expr->emplace_back("+"), expr->emplace_back(num_str);
            addOperatorsDFS(s, target, i + 1, operand1 + operand2, num, expr, result);
            expr->pop_back(), expr->pop_back();
            

            // '-' and '*' could be used only if the expression is not empty.
            if (!expr->empty()) {
                // Case '-':
                expr->emplace_back("-"), expr->emplace_back(num_str);
                addOperatorsDFS(s, target, i + 1, operand1 + operand2, -num, expr, result);
                expr->pop_back(), expr->pop_back();
        
                // Case '*':
                expr->emplace_back("*"), expr->emplace_back(num_str);
                addOperatorsDFS(s, target, i + 1, operand1, operand2 * num, expr, result);
                expr->pop_back(), expr->pop_back();
            }

            // Char is '0'.
            if (num == 0) {
                break;
            }
        }
    }
};
