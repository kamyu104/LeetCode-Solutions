// Time: O(m*n)
// Space: O(n)
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<bool> curr(n + 1, 0);
        for (int i = 0; i <= m; i++)
        {
            bool prev = curr[0];
            curr[0] = !i;
            for (int j = 1; j <= n; j++)
            {
                bool temp = curr[j];
                if (p[j - 1] == '*')
                {
                    curr[j] = curr[j - 2] || (i && curr[j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
                else
                {
                    curr[j] = i && prev && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
                prev = temp;
            }
        }
        return curr[n];
    }
};
