// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int cnt = 0;
        for (int i = 0, j = 0; j < pairs.size(); ++j) {
            if (j == 0 || pairs[i][1] < pairs[j][0]) {
                ++cnt;
                i = j;
            }
        }
        return cnt;
    }
};

