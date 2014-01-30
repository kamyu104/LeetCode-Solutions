// Time Complexity: O(2^n)
// Space Complexity: O(n^2)

class Solution {
    public:      
        vector<vector<string> > partition(string s) {
            const int n = s.size();
            vector<vector<bool> > p(n, vector<bool>(n, false));
            vector<string> path;
            vector<vector<string> > ans;
            buildPalindromeMap(s, p);
            dfs(s, p, 0, path, ans);
            return ans;
        }
    private:
        void buildPalindromeMap(const string &s, vector<vector<bool> > &p) {
            for (int i = s.size() - 1; i >= 0; --i)
                for (int j = i; j < s.size(); ++j)
                    p[i][j] = s[i] == s[j] && ((j - i < 2) || p[i + 1][j - 1]);   
        }
        void dfs(const string &s, const vector<vector<bool> > &p, int start,
                vector<string> &path, vector<vector<string> > &ans) {
            if(start == s.size()) {
                ans.push_back(path);
                return;        
            }
            for(size_t i = start; i < s.size(); ++i) {
                if(p[start][i]) {
                    path.push_back(s.substr(start, i - start + 1));
                    dfs(s, p, i + 1, path, ans);
                    path.pop_back();
                }
            }
        }
};
