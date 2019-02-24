// Time:  O(t + n)
// Space: O(n)

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> degrees(N);
        for (const auto& t : trust) {
            --degrees[t[0] - 1];
            ++degrees[t[1] - 1];
        } 
        for (int i = 0; i < degrees.size(); ++i) {
            if (degrees[i] == N - 1) {
                return i + 1;
            }
        }
        return -1;
    }
};
