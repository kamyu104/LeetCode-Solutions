// Time Complexity: O(3^n)
// Space Complexity: O(n)

class Solution {
    public:
        const vector<string> keyboard { " ", "", "abc", "def", // '0','1','2',...
            "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

        vector<string> letterCombinations(string digits) {
            vector<string> ans;
            string path;
            dfs(digits, 0, path, ans);
            return ans;
        }

    private:
        void dfs(const string &digits, size_t cur, string &path, vector<string> &ans) {
            if(cur == digits.size()) {
                ans.push_back(path);
                return;
            }

            for(auto c: keyboard[digits[cur] - '0']) {
                path.push_back(c);
                dfs(digits, cur + 1, path, ans);
                path.pop_back();
            }
        }
};
