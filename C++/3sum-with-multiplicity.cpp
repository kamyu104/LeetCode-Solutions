// Time:  O(n^2), n is the number of disctinct A[i]
// Space: O(n)

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        unordered_map<int, uint64_t> count;
        for (const auto& a : A) {
            ++count[a];
        }
        uint64_t result = 0;
        for (const auto& kvp1 : count) {
            for (const auto& kvp2 : count) {
                int i = kvp1.first, j = kvp2.first, k = target - i - j;
                if (!count.count(k)) {
                    continue;
                }
                if (i == j && j == k) {
                    result += count[i] * (count[i] - 1) * (count[i] - 2) / 6;
                } else if (i == j && j != k) {
                    result += count[i] * (count[i] - 1) / 2 * count[k];
                } else if (i < j && j < k) {
                    result += count[i] * count[j] * count[k];
                }
            }
        }
        return result % static_cast<int>(1e9 + 7);
    }
};
