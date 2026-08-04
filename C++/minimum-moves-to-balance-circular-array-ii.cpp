// Time:  O(n^2 * logn)
// Space: O(n)

// heap
class Solution {
public:
    long long minMoves(vector<int>& balance) {
        const auto& total = accumulate(cbegin(balance), cend(balance), 0LL);
        if (total < 0) {
            return -1;
        }

        const auto& cost = [&](int i) {
            long long result = 0, prefix = 0;
            priority_queue<int64_t> max_heap;
            for (int j = 0; j < size(balance); ++j) {
                prefix += balance[(i + j) % size(balance)];
                const auto c = clamp(prefix, 0LL, total);
                result += llabs(prefix - c);
                // heap-based l1 isotonic regression
                // reference: https://codeforces.com/contest/13/problem/C
                max_heap.emplace(c);
                if (max_heap.top() > c) {
                    result += max_heap.top() - c;
                    max_heap.pop();
                    max_heap.emplace(c);
                }
            }
            return result;
        };

        long long result = numeric_limits<long long>::max();
        for (int i = 0; i < size(balance); ++i) {
            result = min(result, cost(i));
        }
        return result;
    }
};
