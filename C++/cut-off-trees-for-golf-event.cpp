// Time:  O(t * (logt + m * n)), t is the number of trees
// Space: O(t + m * n)

// Solution Reference: 
// 1. https://discuss.leetcode.com/topic/103532/my-python-solution-inspired-by-a-algorithm/2
// 2. https://discuss.leetcode.com/topic/103562/python-solution-based-on-wufangjie-s-hadlock-s-algorithm
// 3. https://en.wikipedia.org/wiki/A*_search_algorithm
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
            int step = minStep(forest, start, tree.second, m, n);
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
                const pair<int, int>& end,
                int m, int n) {
        int min_steps = abs(start.first - end.first) + abs(start.second - end.second);
        unordered_set<int> lookup;
        vector<pair<int, int>> curr{start}, soon;
        while (true) {
            if (curr.empty()) {
                // cannot find a path in current stack from p1 to p2,
                // try other possible paths in sooner stack with extra 2 steps
                swap(curr, soon);
                min_steps += 2;
            }
            if (curr.empty()) { // no any other possible path
                return -1;
            }
            int i, j;
            tie(i, j) = curr.back(); curr.pop_back();
            if (make_pair(i, j) == end) {
                return min_steps;
            }
            if (!lookup.count(i * n + j)) {
                lookup.emplace(i * n + j);
                vector<pair<pair<int, int>, bool>> expands = {{{i + 1, j}, i < end.first}, 
                                                              {{i - 1, j}, i > end.first},
                                                              {{i, j + 1}, j < end.second},
                                                              {{i, j - 1}, j > end.second}};

                for (const auto& expand : expands) {
                    int i, j;
                    bool is_closer;
                    tie(lvalue(tie(i, j)), is_closer) = expand;
                    if (0 <= i && i < m && 0 <= j && j < n &&
                        forest[i][j] && !lookup.count(i * n + j)) {
                        is_closer ? curr.emplace_back(i, j) : soon.emplace_back(i, j);
                    }
                }
            }
        }

        return min_steps;
    }

    template <class T>
    constexpr T &lvalue(T &&v) {
        return v;
    }
};


// Time:  O(t * (logt + m * n)), t is the number of trees
// Space: O(t + m * n)
class Solution2 {
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
            int step = minStep(forest, start, tree.second, m, n);
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
                const pair<int, int>& end,
                int m, int n) {
        int min_steps = 0;
        unordered_set<int> lookup;
        queue<pair<int, int>> q;
        q.emplace(start);
        lookup.emplace(start.first * n + start.second);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto curr = q.front(); q.pop();
                if (curr == end) {
                    return min_steps;
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
            ++min_steps;
        }
        return -1;
    }
};
