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
        int left = stoi(expression, 0, pos), right = stoi(expression, pos + 1, size(expression));
        int min_val = numeric_limits<int>::max();
        pair<int, int> best;
        const int base2_init = pow(10, size(expression) - (pos + 1) - 1);
        for (int i = 0, base1 = pow(10, pos); i < pos; ++i, base1 /= 10) {
            for (int j = pos + 1, base2 = base2_init; j < size(expression); ++j, base2 /= 10) {
                const int a = left / base1, b = left % base1;
                const int c = right / base2, d = right % base2;
                const auto& val = max(a, 1) * (b + c) * max(d, 1);
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
        int left = stoi(expression.substr(0, pos)), right = stoi(expression.substr(pos + 1));  // Space: O(n)
        int min_val = numeric_limits<int>::max();
        pair<int, int> best;
        const int base2_init = pow(10, size(expression) - (pos + 1) - 1);
        for (int i = 0, base1 = pow(10, pos); i < pos; ++i, base1 /= 10) {
            for (int j = pos + 1, base2 = base2_init; j < size(expression); ++j, base2 /= 10) {
                const int a = left / base1, b = left % base1;
                const int c = right / base2, d = right % base2;
                const auto& val = max(a, 1) * (b + c) * max(d, 1);
                if (val < min_val) {
                    min_val = val;
                    best = {i, j};
                }
            }
        }
        string result = expression.substr(0, best.first);  // Space: O(n)
        result += "(";
        result += expression.substr(best.first, best.second + 1 - best.first);  // Space: O(n)
        result += ")";
        result += expression.substr(best.second + 1);  // Space: O(n)
        return result;
    }
};

// Time:  O(n^3)
// Space: O(n)
// brute force
class Solution3 {
public:
    string minimizeResult(string expression) {
        const auto& pos = expression.find('+');
        int min_val = numeric_limits<int>::max();
        pair<int, int> best;
        for (int i = 0; i < pos; ++i) {
            for (int j = pos + 1; j < size(expression); ++j) {
                const auto& val = (i != 0 ? stoi(expression.substr(0, i)) : 1) *
                                  (stoi(expression.substr(i, pos - i)) + stoi(expression.substr(pos + 1, j + 1 - (pos + 1)))) *
                                  (j + 1 != size(expression) ? stoi(expression.substr(j + 1)) : 1);  // Space: O(n)
                if (val < min_val) {
                    min_val = val;
                    best = {i, j};
                }
            }
        }
        string result = expression.substr(0, best.first);  // Space: O(n)
        result += "(";
        result += expression.substr(best.first, best.second + 1 - best.first);  // Space: O(n)
        result += ")";
        result += expression.substr(best.second + 1);  // Space: O(n)
        return result;
    }
};
