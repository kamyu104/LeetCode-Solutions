// Time:  O(m + n)
// Space: O(1)

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        return accumulate(cbegin(rowCosts) + min(startPos[0], homePos[0]),
                          cbegin(rowCosts) + max(startPos[0], homePos[0]) + 1,
                          -rowCosts[startPos[0]]) +
               accumulate(cbegin(colCosts) + min(startPos[1], homePos[1]),
                          cbegin(colCosts) + max(startPos[1], homePos[1]) + 1,
                          -colCosts[startPos[1]]);
    }
};
