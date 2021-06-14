// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int minOperationsToFlip(string expression) {
        static const unordered_map<char, int> precedence = {{'&', 0}, {'|', 0}};

        vector<vector<int>> operands;
        vector<char> operators;
        for (const auto& c : expression) {
            if (isdigit(c)) {
                operands.push_back({int(c != '0'), int(c != '1')});
            } else if (c == '(') {
                operators.emplace_back(c);
            } else if (c == ')') {
                while (operators.back() != '(') {
                    compute(&operands, &operators);
                }
                operators.pop_back();
            } else if (precedence.count(c)) {
                while (!empty(operators) && precedence.count(operators.back()) && 
                       precedence.at(operators.back()) >= precedence.at(c)) {
                     compute(&operands, &operators);
                }
                operators.emplace_back(c);
            }
        }
        while (!empty(operators)) {
            compute(&operands, &operators);
        }
        return *max_element(cbegin(operands.back()), cend(operands.back()));
    }

private:
    template<typename T>
    void compute(vector<T> *operands, vector<char> *operators) {
        const auto right = operands->back(); operands->pop_back();
        const auto left = operands->back(); operands->pop_back();
        const char op = operators->back(); operators->pop_back();
        if (op == '&') {
            operands->push_back({min(left[0], right[0]), min(left[1] + right[1], min(left[1], right[1]) + 1)});
        } else if (op == '|') {
            operands->push_back({min(left[0] + right[0], min(left[0], right[0]) + 1), min(left[1], right[1])});
        }
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    int minOperationsToFlip(string expression) {
        unordered_set<char> operands_set = {')', '0', '1'};
        vector<tuple<int, int, char>> stk = {{0, 0, ' '}};
        for (const auto& c : expression) {
            if (c == '(') {
                stk.emplace_back(0, 0, ' ');
            } else if (operands_set.count(c)) {
                int dp0 = 0, dp1 = 0;
                if (c == ')') {
                    dp0 = get<0>(stk.back());
                    dp1 = get<1>(stk.back());
                    stk.pop_back();
                } else {
                    dp0 = int(c != '0');
                    dp1 = int(c != '1');
                }
                if (get<2>(stk.back()) == '&') {
                    stk.back() = {min(get<0>(stk.back()), dp0),
                                  min(get<1>(stk.back()) + dp1, min(get<1>(stk.back()), dp1) + 1),
                                  ' '};
                } else if (get<2>(stk.back()) == '|') {
                    stk.back() = {min(get<0>(stk.back()) + dp0, min(get<0>(stk.back()), dp0) + 1),
                                  min(get<1>(stk.back()), dp1),
                                  ' '};
                } else {
                    stk.back() = {dp0, dp1, ' '};
                }
            } else {  // operator
                get<2>(stk.back()) = c;
            }
        }
        return max(get<0>(stk[0]), get<1>(stk[0]));
    }
};
