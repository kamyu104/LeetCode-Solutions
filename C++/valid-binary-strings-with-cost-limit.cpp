// Time:  O(n * 2^n)
// Space: O(n)

// backtracking
class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> result;
        string curr;
        curr.reserve(n);
        const auto backtracking = [&](this auto&& dfs, int total) -> void {
            if (size(curr) == n) {
                result.emplace_back(curr);
                return;
            }
            curr.push_back('0');
            dfs(total);
            curr.pop_back();
            if ((empty(curr) || curr.back() == '0') && total + size(curr) <= k) {
                curr.push_back('1');
                dfs(total + (size(curr) - 1));
                curr.pop_back();
            }
        };

        backtracking(0);
        return result;
    }
};

// Time:  O(n * 2^n)
// Space: O(n)
// bitmasks
class Solution2 {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> result;
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (mask & (mask >> 1)) {
                continue;
            }
            int total = 0;
            string curr(n, '0');
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    total += i;
                    curr[i] = '1';
                }
            }
            if (total <= k) {
                result.emplace_back(move(curr));
            }
        }
        return result;
    }
};
