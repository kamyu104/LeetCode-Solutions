// Time:  O(n)
// Space: O(1)

// greedy, two pointers
class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        const auto& count = [](int n) {
            return static_cast<int64_t>(n + 1) * n / 2;
        };

        const auto& total = count(n);
        if (abs(target) > total || (target - total) % 2) {
            return {};
        }
        vector<int> result(n);
        for (int i = n, left = 0, right = n - 1; i >= 1; --i) {
            if (target - (-i) <= count(i - 1)) {
                target -= -i;
                result[left++] = -i;
            } else {
                target -= i;
                result[right--] = i;
            }
        }
        return result;
    }
};
