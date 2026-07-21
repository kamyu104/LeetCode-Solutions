// Time:  O(n * m)
// Space: O(n)

// prefix sum
class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        vector<int> prefix(size(s) + 1);
        for (int i = 0; i < size(s); ++i) {
            prefix[i + 1] = prefix[i] + (s[i] == '1' ? 1: 0);
        }
        vector<bool> result(size(strs));
        for (int i = 0; i < size(strs); ++i) {
            int left = 0, right = 0;
            for (int j = 0; j < size(strs[i]); ++j) {
                left += (strs[i][j] == '1' ? 1 : 0);
                right = min(right + (strs[i][j] != '0' ? 1 : 0), prefix[j + 1]);
                if (left > right) {
                    break;
                }
            }
            result[i] = left <= prefix.back() && prefix.back() <= right;
        }
        return result;
    }
};
