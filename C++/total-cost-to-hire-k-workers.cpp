// Time:  O(c + klogc)
// Space: O(c)

// heap, two pointers
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int left = candidates;
        int right = max(static_cast<int>(size(costs)) - candidates, candidates) - 1;
        priority_queue<int, vector<int>, greater<int>> min_heap1(cbegin(costs), cbegin(costs) + left);
        priority_queue<int, vector<int>, greater<int>> min_heap2(cbegin(costs) + right + 1, cend(costs));
        int64_t result = 0;
        while (k--) {
            if (empty(min_heap2) || (!empty(min_heap1) && min_heap1.top() <= min_heap2.top())) {
                result += min_heap1.top(); min_heap1.pop();
                if (left <= right) {
                    min_heap1.emplace(costs[left++]);
                }
            } else {
                result += min_heap2.top(); min_heap2.pop();
                if (left <= right) {
                    min_heap2.emplace(costs[right--]);
                }
            }
        }
        return result;
    }
};
