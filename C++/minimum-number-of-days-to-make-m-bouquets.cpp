// Time:  O(nlogd), d is the max day of bloomDay
// Space: O(1)

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (m * k > bloomDay.size()) {
            return -1;
        }
        int left = 1, right = *max_element(cbegin(bloomDay), cend(bloomDay));
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (check(bloomDay, m, k, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool check(const vector<int>& bloomDay, int m, int k, int x) {
        int result = 0, count = 0;
        for (const auto& d : bloomDay) {
            count = (d <= x) ? count + 1 : 0;
            if (count == k) {
                count = 0;
                if (++result == m) {
                    break;
                }
            }
        }
        return result >= m;
    }
};
