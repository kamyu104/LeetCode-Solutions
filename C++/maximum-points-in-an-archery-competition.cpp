// Time:  O(n * 2^n)
// Space: O(n)

// bitmasks
class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> result(size(aliceArrows));
        int best = 0;
        const int full_mask = (1 << size(aliceArrows)) - 1;
        for (int mask = 1; mask <= full_mask; ++mask) {
            const auto& [score, cnt] = check(aliceArrows, mask, numArrows);
            if (score > best) {
                best = score;
                result = move(cnt);
            }
        }
        return result;
    }

private:
    pair<int, vector<int>> check(const vector<int>& aliceArrows, int mask, int numArrows) {
        int score = 0;
        vector<int> cnt(size(aliceArrows));
        for (int k = 0, base = 1; k < size(aliceArrows); ++k, mask >>= 1) {
            if (mask & 1) {
                const int need = aliceArrows[k] + 1;
                if (need > numArrows) {
                    return {0, vector<int>(size(aliceArrows))};
                }
                numArrows -= need;
                cnt[k] = need;
                score += k;
            }
        }
        cnt.back() += numArrows;
        return {score, cnt};
    }
};
