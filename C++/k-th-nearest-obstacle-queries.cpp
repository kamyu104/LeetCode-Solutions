// Time:  O(qlogk)
// Space: O(k)

// heap
class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> result;
        priority_queue<int> max_heap;
        for (const auto& q : queries) {
            max_heap.emplace(abs(q[0]) + abs(q[1]));
            if (size(max_heap) == k + 1) {
                max_heap.pop();
            }
            result.emplace_back(size(max_heap) == k ? max_heap.top() : -1);
        }
        return result;
    }
};
