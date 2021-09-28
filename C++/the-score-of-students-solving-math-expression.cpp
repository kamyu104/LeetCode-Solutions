// Time:  O(n^3 * a^2)
// Space: O(n^2)

class Solution {
public:
    int scoreOfStudents(string s, vector<int>& answers) {
        static const int MAX_ANS = 1000;

        const int n = (size(s) + 1) / 2;
        vector<vector<unordered_set<int>>> dp(n, vector<unordered_set<int>>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i].emplace(s[i * 2] - '0');
        }
        for (int l = 1; l < n; ++l) {
            for (int left = 0; left < n - l; ++left) {
                const int right = left + l;
                for (int k = left; k < right; ++k) {
                    for (const auto& x : dp[left][k]) {
                        for (const auto& y : dp[k + 1][right]) {
                            const int z = (s[2 * k + 1] == '+') ? x + y : x * y;
                            if (z <= MAX_ANS) {
                                dp[left][right].emplace(z);
                            }
                        }
                    }
                }
            }
        }
        const int target = evaluate(s);
        int result = 0;
        for (const auto& ans : answers) {
            if (ans == target) {
                result += 5;
            } else if (dp.front().back().count(ans)) {
                result += 2;
            }
        }
        return result;
    }

private:
    int evaluate(const string& s) {
        static const unordered_map<char, int> precedence = {{'+', 0}, {'*', 1}};

        vector<int64_t> operands;
        vector<char> operators;
        int64_t operand = 0;
        for (const auto& c : s) {
            if (isdigit(c)) {
                operands.emplace_back(c - '0');
            } else {
                while (!empty(operators) && precedence.at(operators.back()) >= precedence.at(c)) {
                     compute(&operands, &operators);
                }
                operators.emplace_back(c);
            }
        }
        while (!empty(operators)) {
            compute(&operands, &operators);
        }
        return operands.back();
    }

    template<typename T>
    void compute(vector<T> *operands, vector<char> *operators) {
        const auto right = operands->back(); operands->pop_back();
        const auto left = operands->back(); operands->pop_back();
        const char op = operators->back(); operators->pop_back();
        if (op == '+') {
            operands->emplace_back(left + right);
        } else if (op == '*') {
            operands->emplace_back(left * right);
        }
    }
};
