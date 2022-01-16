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
