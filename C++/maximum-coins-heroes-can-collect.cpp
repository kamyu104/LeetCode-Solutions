// Time:  O(nlogn + mlogm)
// Space: O(n + m)

// sort, two pointers
class Solution {
public:
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
        vector<int> idxs1(size(heroes));
        iota(begin(idxs1), end(idxs1), 0);
        sort(begin(idxs1), end(idxs1), [&](const auto& a, const auto& b) {
            return heroes[a] < heroes[b];
        });
        vector<int> idxs2(size(monsters));
        iota(begin(idxs2), end(idxs2), 0);
        sort(begin(idxs2), end(idxs2), [&](const auto& a, const auto& b) {
            return monsters[a] < monsters[b];
        });
        vector<long long> result(size(idxs1));
        int i = 0;
        long long curr = 0;
        for (const auto& idx : idxs1) {
            for (; i < size(idxs2); ++i) {
                if (monsters[idxs2[i]] > heroes[idx]) {
                    break;
                }
                curr += coins[idxs2[i]];
            }
            result[idx] = curr;
        }
        return result;
    }
};
