// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if ((source[0] + target[0]) % 2 != (source[1] + target[1]) % 2) {
            return -1;
        }
        return abs(source[0] - target[0]) == abs(source[1] - target[1]) ? 1 : 2;
    }
};
