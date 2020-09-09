// Time:  O(4^n / n^(3/2)) ~= Catalan numbers
// Space: O(n)

// iterative solution
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<tuple<string, int, int>> stk = {{"", n, n}};
        while (!stk.empty()) {
            auto [curr, left, right] = move(stk.back()); stk.pop_back();
            if (left == 0 && right == 0) {
                result.emplace_back(curr);
            }
            if (left < right) {
                stk.emplace_back(curr + ")", left, right - 1);
            }
            if (left > 0) {
                stk.emplace_back(curr + "(", left - 1, right);
            }
        }
        return result;
    }
};

// Time:  O(4^n / n^(3/2)) ~= Catalan numbers
// Space: O(n)
// recursive solution
class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisRecu("", n, n, &result);
        return result;
    }

private:
    void generateParenthesisRecu(const string& curr, int left, int right, vector<string> *result) {
        if (left == 0 && right == 0) {
            result->emplace_back(curr);
        }
        if (left > 0) {
            generateParenthesisRecu(curr + "(", left - 1, right, result);
        }
        if (left < right) {
            generateParenthesisRecu(curr + ")", left, right - 1, result);
        }
    }
};
