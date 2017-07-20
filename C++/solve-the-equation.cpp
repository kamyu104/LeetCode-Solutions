// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string solveEquation(string equation) {
        equation = regex_replace(equation, regex("(^|[+=-])x"), "$011x");

        auto pos = equation.find('=');
        auto l = coef(equation.substr(0, pos));
        auto r = coef(equation.substr(pos + 1));

        auto a = l.first - r.first;
        auto b = r.second - l.second;

        return a != 0 ? "x=" + to_string(b / a) : b != 0 ? "No solution" : "Infinite solutions";
    }

private:
    pair<int, int> coef(string s) {
        auto a = 0, b = 0;
        auto e = regex("(^|[+-])\\d+x?");
        for (regex_token_iterator<string::iterator> it(s.begin(), s.end(), e), end;
             it != end; ++it) {
            (it->str().back() == 'x' ? a : b) += stoi(*it);
        }
        return {a, b};
    } 
};
