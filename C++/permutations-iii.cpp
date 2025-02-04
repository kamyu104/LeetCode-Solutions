// Time:  O(n * n!)
// Space: O(n)

// backtracking, bitmasks
class Solution {
public:
    vector<vector<int>> permute(int n) {
        vector<vector<int>> result;
        vector<int> curr; curr.reserve(n);
        const function<void (int)> backtracking = [&](int lookup) {
            if (size(curr) == n) {
                result.emplace_back(curr);
                return;
            }
            for (int i = 1; i <= n; ++i) {
                if ((lookup & (1 << (i - 1))) || (!empty(curr) && curr.back() % 2 == i % 2)) {
                    continue;
                }
                curr.emplace_back(i);
                backtracking(lookup ^ (1 << (i - 1)));
                curr.pop_back();
            }
        };

        backtracking(0);
        return result;
    }
};
