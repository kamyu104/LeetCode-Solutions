// Time:  O(m * n)
// Space: O(m)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        const auto& n = accumulate(nums.cbegin(), nums.cend(), uint64_t(0ull),
                                   [](const auto& x, const auto& y) {
                                       return max(x, y.size());
                                   });
        vector<int> result;
        vector<pair<int, int>> q;
        for (int r = 0; r < nums.size() + n - 1; ++r) {
            vector<pair<int, int>> new_q;
            if (r < nums.size()) {
                q.emplace_back(r, 0);
            }
            for (int i = q.size() - 1; i >= 0; --i) {
                const auto& [r, c] = q[i];
                result.emplace_back(nums[r][c]);
                if (c + 1 < nums[r].size()) {
                    new_q.emplace_back(r, c + 1);
                }
            }
            reverse(new_q.begin(), new_q.end());
            q = move(new_q);
        }
        return result;
    }
};

// Time:  O(m * n)
// Space: O(m * n)
class Solution2 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> ans;
        for (int r = 0; r < nums.size(); ++r) {
            for (int c = 0; c < nums[r].size(); ++c) {
                if (ans.size() <= r + c) {
                    ans.emplace_back();
                }
                ans[r + c].emplace_back(nums[r][c]);
            }
        }
        vector<int> result;
        for (const auto& row: ans) {
            for (int i = row.size() - 1; i >= 0; --i) {
                result.emplace_back(row[i]);
            }
        }
        return result;
    }
};
