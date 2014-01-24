// Time Complexity: O(2^n/n)??
// Space Complexity: O(n)

class Solution {
    public:
        void generator(vector<string> &ans, string s, int l, int r,  int n) {
            if(l==n) {
                ans.push_back(s.append(n-r, ')'));
                return;
            }
            generator(ans, s+"(", l+1, r, n);
            if(l>r) generator(ans, s+")", l, r+1, n);

        }
        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            generator(ans, "", 0, 0, n);
            return ans;
        }
};
