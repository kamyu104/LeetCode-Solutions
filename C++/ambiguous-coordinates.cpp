// Time:  O(n^4)
// Space: O(n^2)

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> result;
        for (int i = 1; i < S.length() - 2; ++i) {
            const auto& lefts = make(S, 1, i);
            const auto& rights = make(S, i + 1, S.length() - 2 - i);
            for (const auto& left : lefts) {
                for (const auto& right : rights) {
                    string s;
                    s += "(";
                    s += left;
                    s += ", ";
                    s += right;
                    s += ")";
                    result.emplace_back(move(s));
                }
            }
        }
        return result;
    }

private:
    // Time:  O(n^2)
    // Space: O(n^2)
    vector<string> make(const string& S, int i, int n) {
        vector<string> result;
        for (int d = 1; d <= n; ++d) {
            const auto& left = S.substr(i, d);
            const auto& right = S.substr(i + d, n - d);
            if ((left.front() != '0' || left == "0") &&
                 right.back() != '0') {
                string s;
                s += left;
                s += (!right.empty() ? "." : "");
                s += right;
                result.emplace_back(move(s));
            }
        }
        return result;
    }
};
