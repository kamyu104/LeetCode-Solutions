// Time Complexity: O(n^2) ?
// Space Complexity: O(n^2)

class Solution {
    public:
        vector<string> wordBreak(string s, unordered_set<string> &dict) {
            vector<bool> f(s.length() + 1, false);
            vector<vector<bool> > valid(s.length(), vector<bool>(s.length() + 1, false));
            f[0] = true; // null string
            for(int i = 1; i <= s.length(); ++i) {
                for(int j = i - 1; j >= 0; --j) {
                    if(f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                        f[i] = true;
                        valid[j][i] = true; // [j, i) is a word
                    }
                }
            }

            vector<string> path;
            vector<string> ans;

            gen_path(s, valid, s.length(), path, ans);

            return ans;
        }
    private:
        // dfs
        void gen_path(const string &s, vector<vector<bool> > &valid, int len, vector<string> &path, vector<string> &ans) {
            if(len == 0) {
                string tmp;
                for(auto it = path.rbegin(); it != path.rend(); ++it) {
                    tmp += *it + " ";
                }
                tmp.pop_back(); // remove last " "
                ans.push_back(tmp);
            }

            for(int i = 0; i < len; ++i) {
                if(valid[i][len]) {
                    path.push_back(s.substr(i, len - i));
                    gen_path(s, valid, i, path, ans);
                    path.pop_back();
                }
            }
        }
};
