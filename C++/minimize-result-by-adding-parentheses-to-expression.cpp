// Time:  O(n^2)
// Space: O(1)

// brute force
class Solution {
public:
    string minimizeResult(string expression) {
        const auto& stoi = [](const auto& s, int i, int j) {
            if (i == j) {
                return 1;
            }
            int result = 0;
            for (int k = i; k < j; ++k) {
                result = result * 10 + (s[k] - '0');
            }
            return result;
        };
        const auto& pos = expression.find('+');
        int min_val = numeric_limits<int>::max();
        pair<int, int> best;
        for (int i = 0; i < pos; ++i) {
            for (int j = pos + 1; j < size(expression); ++j) {
                const auto& val = stoi(expression, 0, i) *
                                  (stoi(expression, i, pos) + stoi(expression, pos + 1, j + 1)) *
                                  stoi(expression, j + 1, size(expression));
                if (val < min_val) {
                    min_val = val;
                    best = {i, j};
                }
            }
        }
        string result;
        for (int i = 0; i < size(expression); ++i) {
            if (i == best.first) {
                result.push_back('(');
            }
            result.push_back(expression[i]);
            if (i == best.second) {
                result.push_back(')');
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// brute force
class Solution2 {
public:
    string minimizeResult(string expression) {
        const auto& pos = expression.find('+');
        int min_val = numeric_limits<int>::max();
        pair<int, int> best;
        for (int i = 0; i < pos; ++i) {
            for (int j = pos + 1; j < size(expression); ++j) {
                const auto& val = (i != 0 ? stoi(expression.substr(0, i)) : 1) *
                                  (stoi(expression.substr(i, pos - i)) + stoi(expression.substr(pos + 1, j + 1 - (pos + 1)))) *
                                  (j + 1 != size(expression) ? stoi(expression.substr(j + 1)) : 1);
                if (val < min_val) {
                    min_val = val;
                    best = {i, j};
                }
            }
        }
        string result = expression.substr(0, best.first);
        result += "(";
        result += expression.substr(best.first, best.second + 1 - best.first);
        result += ")";
        result += expression.substr(best.second + 1);
        return result;
    }
};
