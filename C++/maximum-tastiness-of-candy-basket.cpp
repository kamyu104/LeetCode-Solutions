// Time:  O(nlogr), r = max(price)-min(price)
// Space: O(1)

// binary search, greedy
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        const auto& check = [&](int x) {  // find max cnt if smallest absolute difference >= x
            int cnt = 0, prev = 0;
            for (int i = 0, j = 0; i < size(price); ++i) {
                if (prev && price[i] - prev < x) {
                    continue;
                }
                if (++cnt == k) {
                    break;
                }
                prev = price[i];
            }
            return cnt >= k;
        };

        sort(begin(price), end(price));
        int left = 1, right = price.back() - price.front();
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (!check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};
