// Time Complexity: O(n^m), where n is max length of number, m is count of segment
// Space Complexity: O(nm)

class Solution {
    public:
        vector<string> restoreIpAddresses(string s) {
            vector<string> ans;
            dfs(s, 0, 4, "", ans);
            return ans;
        }

    private:
        void dfs(const string &s, int start, int step, string ip, vector<string> &ans) {
            if(start == s.size() && step == 0) {
                ip.pop_back();
                ans.push_back(ip);
                return;
            }

            if(s.size() - start < step || s.size() - start > step * 3) // pruing
                return;

            int num = 0;
            for(int i = start; i < start + 3; ++i) {
                num = num * 10 + s[i] - '0';
                if(num > 255) break;
                ip += s[i];
                dfs(s, i + 1, step - 1, ip + '.', ans);
                if(num == 0) break; // only one 0
            }
        }
};
