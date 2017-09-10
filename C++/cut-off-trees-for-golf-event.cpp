// Time:  O(t * (logt + m * n)), t is the number of trees
// Space: O(t + m * n)

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>> > min_heap;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) {
                    min_heap.emplace(forest[i][j], make_pair(i, j));
                }
            }
        }

        pair<int, int> start;
        int result = 0;
        while (!min_heap.empty()) {
            auto tree = min_heap.top(); min_heap.pop();
            int step = minStep(forest, start, tree, m, n);
            if (step < 0) {
                return -1;
            }
            result += step;
            start = tree.second;
        }
        return result;
    }

private:
    int minStep(const vector<vector<int>>& forest,
                const pair<int, int>& start,
                const pair<int, pair<int, int>>& tree,
                int m, int n) {
        int step = 0;
        unordered_set<int> lookup;
        queue<pair<int, int>> q;
        q.emplace(start);
        lookup.emplace(start.first * n + start.second);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto curr = q.front(); q.pop();
                if (curr == tree.second) {
                    return step;
                }
                static const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                               {-1, 0}, {1, 0}};
                for (const auto& direction : directions) {
                    int i = curr.first + direction.first;
                    int j = curr.second + direction.second;
                    if (i < 0 || i >= m || j < 0 || j >= n ||
                        !forest[i][j] || lookup.count(i * n + j)) {
                        continue;
                    }
                    q.emplace(i, j);
                    lookup.emplace(i * n + j);
                }
            }
            ++step;
        }
        return -1;
    }
};
