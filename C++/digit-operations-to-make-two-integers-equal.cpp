// Time:  O(nlogn)
// Space: O(n)

// number theory, dijkstra's algorithm
class Solution {
public:
    int minOperations(int n, int m) {
        const auto& linear_sieve_of_eratosthenes = [](int n) {  // Time: O(n), Space: O(n)
            vector<int> spf(n + 1, -1);
            vector<int> primes;
            for (int i = 2; i <= n; ++i) {
                if (spf[i] == -1) {
                    spf[i] = i;
                    primes.emplace_back(i);
                }
                for (const auto& p : primes) {
                    if (i * p > n || p > spf[i]) {
                        break;
                    }
                    spf[i * p] = p;
                }
            }
            return spf;
        };

        int base = 1;
        for (; base < max(n, m); base *= 10);
        const auto& spf = linear_sieve_of_eratosthenes(base);
        const auto& dijkstra = [&](int start, int target) {
            if (spf[start] == start) {
                return -1;
            }
            unordered_set<int> lookup;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
            min_heap.emplace(start, start);
            while (!empty(min_heap)) {
                const auto [curr, i] = min_heap.top(); min_heap.pop();
                if (lookup.count(i)) {
                    continue;
                }
                lookup.emplace(i);
                if (i == target) {
                    return curr;
                }
                for (int base = 1; base <= i; base *= 10) {
                    const int x = i / base;
                    for (const auto& d : {-1, 1}) {
                        if ((x <= 9 ? 1 : 0) <= x % 10 + d && x % 10 + d <= 9 && 
                            spf[i + d * base] != i + d * base && !lookup.count(i + d * base)) {
                            min_heap.emplace(curr + (i + d * base), i + d * base);
                        }
                    }
                }
            }
            return -1;
        };

        return dijkstra(n, m);
    }
};
