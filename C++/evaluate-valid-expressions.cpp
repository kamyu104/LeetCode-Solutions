// Time:  O(n)
// Space: O(n)

// stack
class Solution {
public:
    long long evaluateExpression(string expression) {
        static const unordered_map<string, function<int64_t (int64_t, int64_t)>> LOOKUP = {
            {"add", [](int64_t a, int64_t b) { return a + b; }},
            {"sub", [](int64_t a, int64_t b) { return a - b; }},
            {"mul", [](int64_t a, int64_t b) { return a * b; }},
            {"div", [](int64_t a, int64_t b) { return a / b; }}
        };
    
        static const string SYMBOLS = "(,)";

        string curr;
        vector<string> ops;
        vector<vector<int64_t>> params(1);
        for (const auto& x : expression) {
            if (SYMBOLS.find(x) == string::npos) {
                curr.push_back(x);
                continue;
            }
            if (x == '(') {
                ops.emplace_back(curr);
                curr.clear();
                params.emplace_back();
                continue;
            }
            if (!empty(curr)) {
                params.back().emplace_back(stoll(curr));
                curr.clear();
            }
            if (x != ')') {
                continue;
            }
            const auto op = ops.back(); ops.pop_back();
            const auto param = params.back(); params.pop_back();
            params.back().emplace_back(LOOKUP.at(op)(param[0], param[1]));
        }
        return !empty(params[0]) ? params[0][0] : stoll(curr);
    }
};
