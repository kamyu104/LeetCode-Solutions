// Time:  O(max(r, c) * wlogw)
// Space: O(w)

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        static const vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
        priority_queue<node, vector<node>, greater<node>> heap;
        unordered_set<int> visited;
        heap.emplace(0, start);

        while (!heap.empty()) {
            int dist = 0;
            vector<int> node;
            tie(dist, node) = heap.top();
            heap.pop();
            if (visited.count(hash(maze, node))) {
                continue;
            }
            if (node[0] == destination[0] &&
                node[1] == destination[1]) {
                return dist;
            }

            visited.emplace(hash(maze, node));
            for (const auto& dir : dirs) {
                int neighbor_dist = 0;
                vector<int> neighbor;
                tie(neighbor_dist, neighbor) = findNeighbor(maze, node, dir);
                heap.emplace(dist + neighbor_dist, neighbor);
            }
        }

        return -1;
    }

private:
    using node = pair<int, vector<int>>;

    node findNeighbor(const vector<vector<int>>& maze,
                      const vector<int>& node, const vector<int>& dir) {
        vector<int> cur_node = node;
        int dist = 0;
    
        while (0 <= cur_node[0] + dir[0] && cur_node[0] + dir[0] < maze.size() &&
               0 <= cur_node[1] + dir[1] && cur_node[1] + dir[1] < maze[0].size() &&
               !maze[cur_node[0] + dir[0]][cur_node[1] + dir[1]]) {
            cur_node[0] += dir[0];
            cur_node[1] += dir[1];
            ++dist;
        }
        return {dist, cur_node};
    }
    
    int hash(const vector<vector<int>>& maze, const vector<int>& node) {
        return node[0] * maze[0].size() + node[1];
    }
};
