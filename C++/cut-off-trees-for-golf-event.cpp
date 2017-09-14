// Time:  O(t * (logt + m * n)), t is the number of trees
// Space: O(t + m * n)

// Solution Reference: 
// 1. https://discuss.leetcode.com/topic/103532/my-python-solution-inspired-by-a-algorithm/2
// 2. https://discuss.leetcode.com/topic/103562/python-solution-based-on-wufangjie-s-hadlock-s-algorithm
// 3. https://en.wikipedia.org/wiki/A*_search_algorithm
// 4. https://cg2010studio.files.wordpress.com/2011/12/dijkstra-vs-a-star.png
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        const auto m = forest.size(), n = forest[0].size();
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
                const int m, const int n) {

        int min_steps = abs(start.first - end.first) + abs(start.second - end.second);
        unordered_set<int> lookup;
        vector<pair<int, int>> closer{start}, detour;
        while (true) {
            if (closer.empty()) {
                // cannot find a path in the current expansion stack which gets closer to end,
                // try other possible paths in another expansion stack with 2-step detour to end
                min_steps += 2;
                swap(closer, detour);
            }
            if (closer.empty()) { // no any other possible path
                return -1;
            }
            int i, j;
            tie(i, j) = closer.back(); closer.pop_back();
            if (make_pair(i, j) == end) {
                return min_steps;
            }
            if (!lookup.count(i * n + j)) {
                lookup.emplace(i * n + j);
                vector<pair<int, int>> expansions = {{i + 1, j}, {i - 1, j}, {i, j + 1}, {i, j - 1}};
                for (const auto& expansion : expansions) {
                    int I, J;
                    bool is_closer;
                    tie(I, J) = expansion;
                    if (0 <= I && I < m && 0 <= J && J < n &&
                        forest[I][J] && !lookup.count(I * n + J)) {
                        bool is_closer = dot({I - i, J - j}, {end.first - i, end.second - j}) > 0;
                        is_closer ? closer.emplace_back(I, J) : detour.emplace_back(I, J);
                    }
                }
            }
        }

        return min_steps;
    }

    inline int dot(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first * b.first + a.second * b.second;
    }
};


// Time:  O(t * (logt + m * n)), t is the number of trees
// Space: O(t + m * n)
class Solution2 {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        const auto m = forest.size(), n = forest[0].size();
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
                const int m, const int n) {

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
