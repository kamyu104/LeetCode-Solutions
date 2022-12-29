// Time:  O(log(min(d1, d2)))
// Space: O(1)

// number theory
class Solution1 {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        const auto& count = [](int cnt, int64_t d1, int64_t d2) {
            const int64_t l = lcm(d1, d2);
            return cnt + cnt / (l - 1) - static_cast<int>(cnt % (l - 1) == 0);
        };

        return max({count(uniqueCnt1, divisor1, 1),
                    count(uniqueCnt2, divisor2, 1),
                    count(uniqueCnt1 + uniqueCnt2, divisor1, divisor2)});
    }
};

// Time:  O(log(min(d1, d2)) + logr)
// Space: O(1)
// binary search
class Solution2 {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        const int64_t l = lcm(static_cast<int64_t>(divisor1), static_cast<int64_t>(divisor2));
        const auto& check = [&](int cnt) {
            return cnt - cnt / divisor1 >= uniqueCnt1 &&
                   cnt - cnt / divisor2 >= uniqueCnt2 &&
                   cnt - cnt / l >= uniqueCnt1 + uniqueCnt2;
        };

        int left = 2, right = numeric_limits<int>::max();
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
