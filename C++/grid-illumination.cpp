// Time:  O(l + q)
// Space: O(l)

class Solution {
 public:
  vector<int> gridIllumination(int N, vector<vector<int>>& lamps,
                               vector<vector<int>>& queries) {
    vector<int> ans;
    unordered_map<int, int> rows;
    unordered_map<int, int> cols;
    unordered_map<int, int> diag1;
    unordered_map<int, int> diag2;
    unordered_set<pair<int, int>, pairHash> lampsSet;

    for (vector<int>& lamp : lamps) {
      int i = lamp[0];
      int j = lamp[1];
      if (lampsSet.insert({i, j}).second) {
        ++rows[i];
        ++cols[j];
        ++diag1[i + j];
        ++diag2[i - j];
      }
    }

    for (const auto& q : queries) {
      int i = q[0];
      int j = q[1];
      if (rows[i] || cols[j] || diag1[i + j] || diag2[i - j]) {
        ans.push_back(1);
        for (int y = max(0, i - 1); y < min(N, i + 2); ++y)
          for (int x = max(0, j - 1); x < min(N, j + 2); ++x)
            if (lampsSet.erase({y, x})) {
              --rows[y];
              --cols[x];
              --diag1[y + x];
              --diag2[y - x];
            }
      } else
        ans.push_back(0);
    }

    return ans;
  }

 private:
  struct pairHash {
    size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
    }
  };
};
