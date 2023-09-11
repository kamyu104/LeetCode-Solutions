// Time:  O(nlogn + mlogm)
// Space: O(n + m)

// sort, two pointers
class Solution {
public:
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
        vector<int> idx1(size(heroes));
        iota(begin(idx1), end(idx1), 0);
        sort(begin(idx1), end(idx1), [&](const auto& a, const auto& b) {
            return heroes[a] < heroes[b];
        });
        vector<int> idx2(size(monsters));
        iota(begin(idx2), end(idx2), 0);
        sort(begin(idx2), end(idx2), [&](const auto& a, const auto& b) {
            return monsters[a] < monsters[b];
        });
        vector<long long> result(size(idx1));
        int i = 0;
        long long curr = 0;
        for (const auto& idx : idx1) {
            for (; i < size(idx2); ++i) {
                if (monsters[idx2[i]] > heroes[idx]) {
                    break;
                }
                curr += coins[idx2[i]];
            }
            result[idx] = curr;
        }
        return result;
    }
};
