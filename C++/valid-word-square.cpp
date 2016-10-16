// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j)             {
                if (j >= words.size() || words[j].size() <= i ||
                   words[j][i] != words[i][j]) {
                   return false;
                }
            }
        }
        return true;
    }
};
