// Time:  O((n * m * 2^n + m * 3^n) * log(n * m * 2^n + m * 3^n)) = O(m * 3^n * log(m * 3^n))
// Space: O(n * m * 2^n + m * 3^n) = O(m * 3^n)

// dijkstra's algorithm, submask enumeration
class Solution {
public:
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        static const auto INF = numeric_limits<double>::max();

        vector<int> lookup(1 << n);
        for (int mask = 1; mask < 1 << n; ++mask) {  // Time: O(n * 2^n)
            for (int i = 0; i < n; ++i) {
                if (!(mask & (1 <<i))) {
                    continue;
                }
                lookup[mask] = max(lookup[mask], time[i]);
            }
        }
        
        vector<vector<vector<double>>> dist(2, vector<vector<double>>(m, vector<double>(1 << n, INF)));
        dist[0][0][(1 << n) - 1] = 0.0;
        using D = tuple<double, int, int, int>;
        priority_queue<D, vector<D>, greater<D>> min_heap;
        min_heap.emplace(0.0, 0, 0, (1 << n) - 1);
        const auto& update = [&](double d, int r, int s, int mask, int submask) {
            const auto& t = lookup[submask] * mul[s];
            const auto& nr = r ^ 1;
            const auto& ns = (s + static_cast<int>(t)) % m;
            const auto& new_mask = mask ^ submask;
            const auto& nd = d + t;
            if (dist[nr][ns][new_mask] > nd) {
                dist[nr][ns][new_mask] = nd;
                min_heap.emplace(nd, nr, ns, new_mask);
            }
        };

        while (!empty(min_heap)) {
            const auto [d, r, s, mask] = min_heap.top(); min_heap.pop();  // Total Time: O((n * m * 2^n + m * 3^n) * log(n * m * 2^n + m * 3^n))
            if (d != dist[r][s][mask]) {
                continue;
            }
            if (mask == 0) {
                assert(r == 1);
                return d;
            }
            if (r == 0) {
                for (int submask = mask; submask; submask = (submask - 1) & mask) {  // Total Time: O(m * 3^n)
                    if (__builtin_popcount(submask) > k) {
                        continue;
                    }
                    update(d, r, s, mask, submask);
                }
            } else {
                for (int i = 0; i < n; ++i) {  // Total Time: O(n * m * 2^n)
                    if (mask & (1 << i)) {
                        continue;
                    }
                    update(d, r, s, mask, 1 << i);
                }
            }
        }
        return -1.0;
    }
};
