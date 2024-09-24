// Time:  O(nlogr), r = min(workerTimes) * (mountainHeight + 1) * mountainHeight / 2
// Space: O(1)

// binary search, quadratic equation
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        const auto& binary_search = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };
    
        const int64_t mn = ranges::min(workerTimes);
        int64_t left = mn, right = mn * (mountainHeight + 1) * mountainHeight / 2;
        return binary_search(left, right, [&](const auto& target) {
            // t * (1 + 2 + 3 + ... + x) <= target
            // t * (x+1)*x/2 <= target
            // x^2+x-2*target/t <= 0
            // x <= (-1+(1+8*target/t)**0.5)/2
            int64_t total = 0;
            for (const auto& t : workerTimes) {
                total += int((-1 + sqrt(1 + double(8) * target / t)) / 2);
            }
            return total >= mountainHeight;
        });
    }
};

// Time:  O(hlogn)
// Space: O(n)
// heap
class Solution2 {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        using T = tuple<int64_t, int, int64_t>;
        vector<T> tmp;
        for (int i = 0; i < size(workerTimes); ++i) {
            tmp.emplace_back(0 + 1 * workerTimes[i], i, 1);
        }
        priority_queue<T, vector<T>, greater<T>> min_heap(cbegin(tmp), cend(tmp));
        int64_t result = 0;
        for (int _ = 0; _ < mountainHeight; ++_) {
            const auto [t, i, x] = min_heap.top(); min_heap.pop();
            min_heap.emplace(t + (x + 1) * workerTimes[i], i, x + 1);
            result = t;
        }
        return result;
    }
};
