// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int left = 0, min_moves = numeric_limits<int>::max();
        int max_moves = max(*stones.crbegin() - stones[1], *next(stones.crbegin(), 1) - stones[0]) -
                        (stones.size() - 2);
        for (int right = 0; right < stones.size(); ++right) {
            while (stones[right] - stones[left] + 1 > stones.size()) {  // find window size <= len(stones)
                ++left;
            }
            if (stones.size() - (right - left + 1) == 1 &&
                stones[right] - stones[left] + 1 == stones.size() - 1) {
                min_moves = min(min_moves, 2);  // case (1, 2, 3, 4), 7
            } else {
                // move stones not in this window
                min_moves = min(min_moves, static_cast<int>(stones.size()) - (right - left + 1));
            }
        }
        return {min_moves, max_moves};
    }
};
