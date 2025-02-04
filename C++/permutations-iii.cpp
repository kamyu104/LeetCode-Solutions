// Time:  O(n * n!)
// Space: O(n)

// backtracking, bitmasks
class Solution {
public:
    vector<vector<int>> permute(int n) {
        vector<vector<int>> result;
        int lookup = 0;
        vector<int> curr; curr.reserve(n);
        const function<void ()> backtracking = [&]() {
            if (size(curr) == n) {
                result.emplace_back(curr);
                return;
            }
            for (int i = 1; i <= n; ++i) {
                if ((lookup & (1 << (i - 1)))|| (!empty(curr) && curr.back() % 2 == i % 2)) {
                    continue;
                }
                lookup ^= 1 << (i - 1);
                curr.emplace_back(i);
                backtracking();
                curr.pop_back();
                lookup ^= 1 << (i - 1);
            }
        };

        backtracking();
        return result;
    }
};
