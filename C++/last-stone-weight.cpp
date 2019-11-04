// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;
        for (const auto& x : stones) {
            max_heap.emplace(x);
        }
        for (int i = 0; i + 1 < stones.size(); ++i) {
            auto x = max_heap.top(); max_heap.pop();
            auto y = max_heap.top(); max_heap.pop();
            max_heap.emplace(abs(x - y));
        }
        return max_heap.top();
    }
};
