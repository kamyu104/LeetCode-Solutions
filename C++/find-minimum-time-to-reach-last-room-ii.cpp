// Time:  O(n * m * logn(n * m))
// Space: O(n * m)

// dijkstra's algorithm
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        static const int INF = numeric_limits<int>::max();
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        const auto& dijkstra = [&](const pair<int, int>& start, const pair<int, int>& target) {
            vector<vector<int>> dist(size(moveTime), vector<int>(size(moveTime[0]), INF));
            dist[start.first][start.second] = 0;
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> min_heap;
            min_heap.emplace(dist[start.first][start.second], start.first, start.second);
            while (!empty(min_heap)) {
                const auto [curr, i, j] = min_heap.top(); min_heap.pop();
                if (curr != dist[i][j]) {
                    continue;
                }
                if (pair(i, j) == target) {
                    break;
                }
                for (const auto& [di, dj] : DIRECTIONS) {
                    const int ni = i + di, nj = j + dj;
                    const int c = (i + j) % 2 + 1;
                    if (!(0 <= ni && ni < size(moveTime) && 0 <= nj && nj < size(moveTime[0]) && dist[ni][nj] > max(moveTime[ni][nj], curr) + c)) {
                        continue;
                    }
                    dist[ni][nj] = max(moveTime[ni][nj], curr) + c;
                    min_heap.emplace(dist[ni][nj], ni, nj);
                }
            }
            return dist[target.first][target.second];
        };

        return dijkstra({0, 0}, {size(moveTime) - 1, size(moveTime[0]) - 1});
    }
};
