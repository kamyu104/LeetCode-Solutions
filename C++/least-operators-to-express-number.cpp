// Time:  O(logn/logx) = O(1)
// Space: O(logn) = O(1)

class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        int pos = 0, neg = 0, k;
        for (k = 0; target > 0; ++k, target /= x) {
            int r = target % x;
            if (k > 0) {
                tie(pos, neg) = make_pair(
                                    min(r * k + pos, (r + 1) * k + neg),
                                    min((x - r) * k + pos, (x - r - 1) * k + neg)
                                );
            } else {
                tie(pos, neg) = make_pair(r * 2, (x - r) * 2);
            }
        }
        return min(pos, k + neg) - 1;
    }
};
