// Time:  O(n)
// Space: O(n)

class Solution {
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
