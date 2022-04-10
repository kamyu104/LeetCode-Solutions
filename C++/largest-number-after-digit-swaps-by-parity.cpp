// Time:  O(logn)
// Space: O(1)

// counting sort
class Solution {
public:
    int largestInteger(int num) {
        const auto& count = [](auto num) {
            vector<int> cnt(10);
            for (; num; num /= 10) {
                ++cnt[num % 10];
            }
            return cnt;
        };
        
        auto cnt = count(num);
        int result = 0;
        vector<int> idx = {0, 1};
        for (int64_t base = 1; num; num /= 10, base *= 10) {
            const auto parity = (num % 10) % 2;
            for (; !cnt[idx[parity]] ; idx[parity] += 2);
            --cnt[idx[parity]];
            result += idx[parity] * base;
        }
        return result;
    }
};
