// Time:  O(nlogn + r^2), r = max(rewardValues)
// Space: O(r)

// sort, dp, bitset
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        static const int MAX_VALUE = 50000;

        unordered_set<int> v_set(cbegin(rewardValues), cend(rewardValues));
        vector<int> sorted_v(cbegin(v_set), cend(v_set));
        sort(begin(sorted_v), end(sorted_v));
        bitset<(MAX_VALUE - 1) + 1> dp, mask;
        dp[0] = true;
        int i = 0;
        for (int i = 0, j = 0; i + 1 < size(sorted_v); ++i) {
            while (j < sorted_v[i]) {
                mask[j++] = true;
            }
            dp |= (dp & mask) << sorted_v[i];
        }
        int result = sorted_v.back() - 1;
        for (; !dp[result]; --result);
        return sorted_v.back() + result;
    }
};

// Time:  O(nlogn + r^2), r = max(rewardValues)
// Space: O(r)
// sort, dp, bitset
class Solution2 {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        static const int MAX_VALUE = 50000;

        unordered_set<int> v_set(cbegin(rewardValues), cend(rewardValues));
        vector<int> sorted_v(cbegin(v_set), cend(v_set));
        sort(begin(sorted_v), end(sorted_v));
        bitset<(MAX_VALUE * 2 - 1) + 1> dp, mask;
        dp[0] = true;
        int i = 0;
        for (int i = 0, j = 0; i < size(sorted_v); ++i) {
            while (j < sorted_v[i]) {
                mask[j++] = true;
            }
            dp |= (dp & mask) << sorted_v[i];
        }
        int result = 2 * sorted_v.back() - 1;
        for (; !dp[result]; --result);
        return result;
    }
};
