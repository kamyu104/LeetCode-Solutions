// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string result(s.length(), 0);
        for (int i = 0; i < s.length(); ++i) {
            result[indices[i]] = s[i];
        }
        return result;
    }
};
