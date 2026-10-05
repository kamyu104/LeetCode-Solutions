// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        return abs(source[0] - target[0]) == abs(source[1] - target[1]) && abs(source[1] - target[1]) != 0 ? 1 : (source[0] != target[0]) + (source[1] != target[1]);
    }
};
