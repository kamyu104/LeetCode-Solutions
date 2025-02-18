// Time:  O(nlogn)
// Space: O(1)

// sort, greedy
class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        const int l = size(pizzas) / 4;
        sort(begin(pizzas), end(pizzas), greater<int>());
        int64_t result = 0;
        for (int i = 0; i < (l + 1) / 2; ++i) {
            result += pizzas[i];
        }
        for (int i = (l + 1) / 2 + 1; i < (l + 1) / 2 + (l / 2) * 2; i += 2) {
            result += pizzas[i];
        }
        return result;
    }
};
