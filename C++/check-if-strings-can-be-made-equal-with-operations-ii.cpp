// Time:  O(1)
// Space: O(1)

// freq table
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<vector<int>> cnt1(2, vector<int>(26)), cnt2(2, vector<int>(26));
        for (int i = 0; i < 2; ++i) {
            for (int j = i; j < size(s1); j += 2) {
                ++cnt1[i][s1[j] - 'a'];
            }
            for (int j = i; j < size(s1); j += 2) {
                ++cnt2[i][s2[j] - 'a'];
            }
        }
        return cnt1 == cnt2;
    }
};
