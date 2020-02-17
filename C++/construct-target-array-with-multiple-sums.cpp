// Time:  O(log(max(t)) * logn)
// Space: O(n)

class Solution {
public:
    bool isPossible(vector<int>& target) {
        // (1) x + remain = y
        // (2) y + remain = total
        // (1) - (2) => x - y = y - total
        //           => x = 2*y - total
        auto total = accumulate(cbegin(target), cend(target), 0ll);
        priority_queue<int> max_heap(cbegin(target), cend(target));
        while (total != target.size()) {
            const auto y = max_heap.top(); max_heap.pop();
            const auto& remain = total - y;
            auto x = y - remain;
            if (x <= 0) {
                return false;
            }
            if (x > remain) {  // for case [1, 1000000000]
                x = x % remain + remain;
            }
            max_heap.emplace(x);
            total = x + remain;
        }
        return true;
    }
};
