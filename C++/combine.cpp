// Time Complexity: O(n!)
// Space Complexity: O(n)

class Solution {
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
