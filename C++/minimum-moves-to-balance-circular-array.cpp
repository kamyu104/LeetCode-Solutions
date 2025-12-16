// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    long long minMoves(vector<int>& balance) {
        const int n =  size(balance);
        int i = 0;
        for (; i < n; ++i) {
            if (balance[i] < 0) {
                break;
            }
        }
        if (i == n) {
            return 0;
        }
        if (accumulate(cbegin(balance), cend(balance), 0ll) < 0) {
            return -1;
        }
        int64_t result = 0;
        for (int64_t d = 1; d <= n / 2; ++d) {
            const auto& c = min(balance[(i + d) %n] + balance[(((i - d) % n) + n) % n], -balance[i]);
            result += c * d;
            balance[i] += c;
            if (!balance[i]) {
                break;
            }
        }
        return result;
    }
};
