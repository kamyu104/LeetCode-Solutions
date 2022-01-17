// Time:  O(nlogm)
// Space: O(1)

// greedy
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int64_t total = accumulate(cbegin(batteries), cend(batteries), 0ll);
        make_heap(begin(batteries), end(batteries));
        while (batteries.front() > total / n) {
            --n;
            total -= batteries.front();
            pop_heap(begin(batteries), end(batteries)); batteries.pop_back();
        }
        return total / n;
    }
};

// Time:  O(nlogr), r is the range of possible minutes
// Space: O(1)
// binary search
class Solution2 {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        auto check = [&n, &batteries](int64_t x) {
            return accumulate(cbegin(batteries), cend(batteries), 0ll,
                              [&x](const auto& total, const int64_t b) {
                                  return total + min(b, x);
                              }) >= n * x;
        };
        int64_t left = *min_element(cbegin(batteries), cend(batteries));
        int64_t right = accumulate(cbegin(batteries), cend(batteries), 0ll) / n;
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (!check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};
