// Time:  O(klogk)
// Space: O(k)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int kth_smallest = 0;

        using P = pair<int, int>;
        const auto Compare = [&matrix](const P& a, const P& b) {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };

        priority_queue<P, vector<P>, decltype(Compare)> min_heap(Compare);
        min_heap.emplace(0, 0);

        for (int i = 0; i < k; ++i) {
            const auto idx = min_heap.top();
            min_heap.pop();
            
            if (idx.first == 0 && idx.second + 1 < matrix[0].size()) {
                min_heap.emplace(0, idx.second + 1);
            }

            if (idx.first + 1 < matrix.size()) {
                min_heap.emplace(idx.first + 1, idx.second);
            }

            kth_smallest = matrix[idx.first][idx.second];
        }

        return kth_smallest;
    }
};
