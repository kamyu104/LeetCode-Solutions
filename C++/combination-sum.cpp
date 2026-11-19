// Time:  O(k * n^k)
// Space: O(k)

class Solution {
  vector<vector<int>> ans;
  void findCombinations(vector<int> &candidates, int begin, vector<int> &sol, int target) {
    if (target < 0)
      return;
    if (target == 0) {
      ans.push_back(sol);
      return;
    }
    for (int i = begin; i < candidates.size(); i++) {
      sol.push_back(candidates[i]);
      findCombinations(candidates, i, sol, target - candidates[i]);
      sol.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    ans = {};
    vector<int> sol = {};
    findCombinations(candidates, 0, sol, target);
    return ans;
  }
};