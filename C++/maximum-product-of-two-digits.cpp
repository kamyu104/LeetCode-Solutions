// Time:  O(d + 10)
// Space: O(10)

// freq table, greedy
class Solution {
public:
    int maxProduct(int n) {
        static const int MAX_COUNT = 2;
        const auto& count = [](int n) {
            vector<int> cnt(10);
            for (; n; n /= 10) {
                ++cnt[n % 10];
            }
            return cnt;
        };

        auto cnt = count(n);
        int result = 1;
        for (int d = 9, c = MAX_COUNT; d >= 0; --d) {
            if (c == 0) {
                break;
            }
            for (; cnt[d]; --cnt[d]) {
                if (c == 0) {
                    break;
                }
                --c;
                result *= d;
            }
        }
        return result;
    }
};
