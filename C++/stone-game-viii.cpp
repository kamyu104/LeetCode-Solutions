// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        partial_sum(begin(stones), end(stones), begin(stones));
        return accumulate(next(rbegin(stones)), prev(rend(stones)), stones.back(),
                          [](int curr, int x) { return max(curr, x - curr); });
    }
};
