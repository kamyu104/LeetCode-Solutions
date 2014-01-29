// Time Complexity: O(n!)
// Space Complexity: O(1)

class Solution {
    public:
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int> > ans;
            vector<int> v;
            dfs(candidates, target, 0, v, ans);
            return ans;
        }

    private:
        void dfs(vector<int>& candidates, int gap, int begin, vector<int>& v,vector<vector<int> > &ans) {
            if (gap == 0) {
                ans.push_back(v);
                return;
            }

            for (size_t i = begin; i < candidates.size(); i++) {
                if (gap < candidates[i]) return;
                v.push_back(candidates[i]);
                dfs(candidates, gap - candidates[i], i, v, ans);
                v.pop_back();
            }
        }
};
