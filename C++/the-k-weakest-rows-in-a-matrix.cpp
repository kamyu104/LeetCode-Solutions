// Time:  O(m * n + klogk)
// Space: O(m)

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> nums;
        for (int i = 0; i < mat.size(); ++i) {
            nums.emplace_back(accumulate(mat[i].cbegin(), mat[i].cend(), 0), i);
        }
        nth_element(nums.begin(), nums.begin() + k, nums.end());
        sort(nums.begin(), nums.begin() + k);
        vector<int> result;
        transform(nums.cbegin(), nums.cbegin() + k, back_inserter(result),
                  [](const auto& x) {
                      return x.second;
                  });
        return result;
    }
};
