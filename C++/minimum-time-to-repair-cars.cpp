// Time:  O(mx * log(mn * c^2)) = O(mx * (logc + log(mn))), c = cars, mx = max(ranks), mn = min(ranks)
// Space: O(mx)

// freq table, binary search
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        unordered_map<int, int> cnt;
        for (const auto& r : ranks) {
            ++cnt[r];
        }
        const auto& check = [&](int64_t x) {
            return accumulate(cbegin(cnt), cend(cnt), 0LL, [&](const auto& total, const auto& v) {
                return total + static_cast<int64_t>(sqrt(x / v.first)) * v.second;
            }) >= cars;
        };

        const int64_t mn = min_element(cbegin(cnt), cend(cnt), [](const auto& a, const auto& b) {
            return a.first < b.first;
        })->first;
        int64_t left = 1, right = mn * cars * cars;
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

// Time:  O(c * log(mx)), c = cars, mx = max(ranks)
// Space: O(mx)
// freq table, heap, simulation
class Solution2 {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        unordered_map<int, int> cnt;
        for (const auto& r : ranks) {
            ++cnt[r];
        }
        vector<pair<int64_t, int>> tmp;
        for (const auto& [r, _] : cnt) {
            tmp.emplace_back(r * 1 * 1, 1);
        }
        using P = pair<int64_t, int>;
        priority_queue<P, vector<P>, greater<P>> max_heap(cbegin(tmp), cend(tmp));
        int64_t result;
        while (cars > 0) {
            auto [t, k] = max_heap.top(); max_heap.pop();
            const auto& r = t / k / k;
            cars -= cnt[r];
            ++k;
            max_heap.emplace(r * k * k, k);
            result = t;
        }
        return result;
    }
};
