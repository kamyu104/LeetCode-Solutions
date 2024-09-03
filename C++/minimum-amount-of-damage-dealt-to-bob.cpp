// Time:  O(nlogn)
// Space: O(n)

// sort, greedy
class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        const auto& ceil_divide = [](int a, int b) {
            return (a + b - 1) / b;
        };
        for (auto& h : health) {
            h = ceil_divide(h, power);
        }
        vector<int> idxs(size(health));
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
            return health[a] * damage[b] < health[b] * damage[a];
        });
        int64_t result = 0, t = 0;
        for (const auto& i : idxs) {
            t += health[i];
            result += t * damage[i];
        }
        return result;
    }
};
