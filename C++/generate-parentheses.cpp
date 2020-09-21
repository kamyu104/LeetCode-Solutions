// Time:  O(4^n / n^(3/2)) ~= Catalan numbers
// Space: O(n)

// iterative solution
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<tuple<string, int, int>> stk = {{"", n, n}};
        while (!stk.empty()) {
            const auto [curr, left, right] = move(stk.back()); stk.pop_back();
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
        string curr;
        generateParenthesisRecu(n, n, &curr, &result);
        return result;
    }

private:
    void generateParenthesisRecu(int left, int right, string *curr, vector<string> *result) {
        if (left == 0 && right == 0) {
            result->emplace_back(*curr);
        }
        if (left > 0) {
            curr->push_back('(');
            generateParenthesisRecu(left - 1, right, curr, result);
            curr->pop_back();
        }
        if (left < right) {
            curr->push_back(')');
            generateParenthesisRecu(left, right - 1, curr, result);
            curr->pop_back();
        }
    }
};
