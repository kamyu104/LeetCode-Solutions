// Time:  O(nlogn)
// Space: O(n)

// prefix sum, binary search
class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        vector<long long> prefix(size(damage) + 1);
        for (int i = 0; i + 1 < size(prefix); ++i) {
            prefix[i + 1] = prefix[i] + damage[i];
        }
        int64_t result = 0;
        for (int i = 0; i < size(damage); ++i) {
            const auto& j = distance(cbegin(prefix), lower_bound(cbegin(prefix), cend(prefix), prefix[i + 1] + requirement[i] - hp));
            if (j <= i) {
                result += i - j + 1;
            }
        }
        return result;
    }
};
