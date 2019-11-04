// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool parseBoolExpr(string expression) {
        int i = 0;
        return parse(expression, &i);
    }

private:
    bool parse(const string& expression, int *i) {
        static const string ops = "&|!";
        if (ops.find(expression[*i]) == string::npos) {
            bool result = expression[*i] == 't';
            ++(*i);
            return result;
        }
        const auto& op = expression[*i];
        *i += 2;
        vector<bool> stk;
        while (expression[*i] != ')') {
            if (expression[*i] == ',') {
                ++(*i);
                continue;
            }
            stk.emplace_back(parse(expression, i));
        }
        ++(*i);
        if (op == '&') {
            return all_of(stk.cbegin(), stk.cend(),
                          [](bool val) { return val; });
        }
        if (op == '|') {
            return any_of(stk.cbegin(), stk.cend(),
                          [](bool val) { return val; });
        }
        return !stk[0];
    }
};
