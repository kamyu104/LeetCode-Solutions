// Time:  O(k * log(min(n, m, k))), with n x m matrix
// Space: O(min(n, m, k))

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int kth_smallest = 0;

        using P = pair<int, pair<int, int>>;
        priority_queue<P, vector<P>, greater<P>> q;
        auto push = [&matrix, &q](int i, int j) {
            if (matrix.size() > matrix[0].size()) {
                if (i < matrix[0].size() && j < matrix.size()) {
                    q.emplace(matrix[j][i], make_pair(j, i));
                }
            } else {
                if (i < matrix.size() && j < matrix[0].size()) {
                    q.emplace(matrix[i][j], make_pair(i, j));
                }
            }
        };

        push(0, 0);
        while (!q.empty() && k--) {
            auto tmp = q.top(); q.pop();
            kth_smallest = tmp.first;
            int i, j;
            tie(i, j) = tmp.second;
            push(i, j + 1);
            if (j == 0) {
                push(i + 1, 0);
            }
        }
        return kth_smallest; 
    }
};
