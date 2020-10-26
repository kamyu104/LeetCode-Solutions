// Time:  O(k * C(n, k))
// Space: O(k)

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        static const auto& add_result =
            [](const auto& nums, const auto& idxs, auto *result) {
                result->emplace_back();
                transform(cbegin(idxs), cend(idxs), back_inserter(result->back()),
                          [&nums](const auto& i) {
                              return nums[i];
                          });
            };
        static const auto& next_pos =
            [](const auto& n, const auto& k, const auto& idxs) {
                int i = k - 1;
                for (; i >= 0; --i) {
                    if (idxs[i] != i + n - k) {
                        break;
                    }
                }
                return i;
            };

        if (k > n) {
            return {};
        }
        vector<int> nums(n), idxs(k);
        iota(begin(nums), end(nums), 1), iota(begin(idxs), end(idxs), 0);
        vector<vector<int>> result;
        add_result(nums, idxs, &result);
        for (int i; (i = next_pos(n, k, idxs)) >= 0;) {
            ++idxs[i];
            for (int j = i + 1; j < k; ++j) {
                idxs[j] = idxs[j - 1] + 1;
            }
            add_result(nums, idxs, &result);
        }
        return result;
    }
};

// Time:  O(k * C(n, k))
// Space: O(k)
class Solution2 {
public:
    void dfs(int n, int k, int start, vector<int> &path, vector<vector<int> > &ans) {
        if(k == 0) {
            ans.push_back(path);
            return;
        }

        for(int i = start; i <= n; ++i) {
            path.push_back(i);
            dfs(n, k - 1, i + 1, path, ans);
            path.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> path;
        dfs(n, k, 1, path, ans);
        return ans;
    }
};
