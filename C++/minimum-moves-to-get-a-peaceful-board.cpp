// Time:  O(n)
// Space: O(n)
// greedy, prefix sum

class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        const auto& count = [&](const auto& cnt) {
            int result = 0, prefix = 0;
            for (int i = 0; i < size(rooks); ++i) {
                prefix += cnt[i];
                result += abs(prefix - (i + 1));
            }
            return result;
        };

        vector<int> cnt1(size(rooks)), cnt2(size(rooks));
        for (const auto& x : rooks) {
            ++cnt1[x[0]];
            ++cnt2[x[1]];
        }
        return count(cnt1) + count(cnt2);
    }
};
