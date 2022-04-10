// Time:  O(nlogn)
// Space: O(1)

// sort, prefix sum, greedy, two pointers, improved from solution3
class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        const auto it = partition(begin(flowers), end(flowers), [&target](int x) { return x < target; });
        sort(begin(flowers), it);
        const long long n = distance(begin(flowers), it);
        long long prefix = 0, suffix = accumulate(begin(flowers), it, 0ll);
        long long result = 0;
        for (long long right = 0, left = 0; right <= n; ++right) {
            if (right) {
                suffix -= flowers[right - 1];
            }
            const auto total = newFlowers - (static_cast<long long>(n - right) * target - suffix);
            if (total < 0) {
                continue;
            }
            while (!(left == right || (left && (total + prefix) / left <= flowers[left]))) {
                prefix += flowers[left++];
            }
            const auto mn = min(left ? (total + prefix) / left : 0ll, static_cast<long long>(target) - 1);
            result = max(result, mn * partial + (static_cast<long long>(size(flowers)) - right) * full);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(1)
// sort, prefix sum, greedy, two pointers, improved from solution4
class Solution2 {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        const auto it = partition(begin(flowers), end(flowers), [&target](int x) { return x < target; });
        sort(begin(flowers), it);
        const long long n = distance(begin(flowers), it);
        vector<long long> prefix(n + 1);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + flowers[i];
        }
        long long result = 0, suffix = 0;
        for (long long right = n, left = n; right >= 0; --right) {
            if (right != n) {
                suffix += flowers[right];
            }
            const auto total = newFlowers - (static_cast<long long>(n - right) * target - suffix);
            if (total < 0) {
                break;
            }
            left = min(left, right);
            while (!(left == 0 || (prefix[left] - prefix[left - 1]) * left - prefix[left] <= total)) {
                --left;
            }
            const auto mn = min(left ? (total + prefix[left]) / left : 0ll, static_cast<long long>(target) - 1);
            result = max(result, mn * partial + (static_cast<long long>(size(flowers)) - right) * full);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// sort, prefix sum, greedy, binary search
class Solution3 {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        const auto& check = [](const auto& prefix, const auto& total, auto x) {
            return x && (total + prefix[x]) / x <= prefix[x + 1] - prefix[x];
        };
        const auto& binary_search = [&check](const auto& prefix, const auto& total, auto left, auto right) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (check(prefix, total, mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };
        const auto it = partition(begin(flowers), end(flowers), [&target](int x) { return x < target; });
        sort(begin(flowers), it);
        const long long n = distance(begin(flowers), it);
        vector<long long> prefix(n + 1);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + flowers[i];
        }
        long long suffix = accumulate(begin(flowers), it, 0ll);
        long long result = 0;
        for (long long right = 0; right <= n; ++right) {
            if (right) {
                suffix -= flowers[right - 1];
            }
            const auto total = newFlowers - (static_cast<long long>(n - right) * target - suffix);
            if (total < 0) {
                continue;
            }
            const auto left = binary_search(prefix, total, 0, right - 1);
            const auto mn = min(left ? (total + prefix[left]) / left : 0ll, static_cast<long long>(target) - 1);
            result = max(result, mn * partial + (static_cast<long long>(size(flowers)) - right) * full);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// sort, prefix sum, greedy, binary search
class Solution4 {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        const auto& check = [](const auto& prefix, const auto& total, auto x) {
            return (prefix[x] - prefix[x - 1]) * x - prefix[x] <= total;
        };
        const auto& binary_search_right = [&check](const auto& prefix, const auto& total, auto left, auto right) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (!check(prefix, total, mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };
        const auto it = partition(begin(flowers), end(flowers), [&target](int x) { return x < target; });
        sort(begin(flowers), it);
        const long long n = distance(begin(flowers), it);
        vector<long long> prefix(n + 1);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + flowers[i];
        }
        long long result = 0, suffix = 0;
        for (long long right = n; right >= 0; --right) {
            if (right != n) {
                suffix += flowers[right];
            }
            const auto total = newFlowers - (static_cast<long long>(n - right) * target - suffix);
            if (total < 0) {
                break;
            }
            const auto left = binary_search_right(prefix, total, 1, right);
            const auto mn = min(left ? (total + prefix[left]) / left : 0ll, static_cast<long long>(target) - 1);
            result = max(result, mn * partial + (static_cast<long long>(size(flowers)) - right) * full);
        }
        return result;
    }
};
