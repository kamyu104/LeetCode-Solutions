// Time:  O(max(r, c) * wlogw)
// Space: O(w^2)

class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        static const unordered_map<string, vector<int>> dirs = {{"u", {-1, 0}}, {"r", {0, 1}},
                                                                {"l", {0, -1}}, {"d", {1, 0}}};
        queue<node> heap;
        unordered_set<int> visited;
        heap.emplace(0, make_pair("", ball));

        while (!heap.empty()) {
            int dist = 0;
            string path;
            vector<int> node;
            tie(dist, lvalue(tie(path, node))) = heap.front();
            heap.pop();
            if (visited.count(hash(maze, node))) {
                continue;
            }

            if (node[0] == hole[0] &&
                node[1] == hole[1]) {
                return path;
            }

            visited.emplace(hash(maze, node));
            for (const auto& kvp : dirs) {
                int neighbor_dist = 0;
                string dir;
                vector<int> neighbor;
                tie(neighbor_dist, lvalue(tie(dir, neighbor))) = findNeighbor(maze, hole, node, kvp);
                heap.emplace(dist + neighbor_dist, make_pair(path + dir, neighbor));
            }
        }

        return "impossible";
    }

private:
    using node = pair<int, pair<string, vector<int>>>;

    node findNeighbor(const vector<vector<int>>& maze, const vector<int>& hole,
                      const vector<int>& node, const pair<string, vector<int>>& kvp) {
        string dir;
        vector<int> vec;
        tie(dir, vec) = kvp;
        vector<int> cur_node = node;
        int dist = 0;
    
        while (0 <= cur_node[0] + vec[0] && cur_node[0] + vec[0] < maze.size() &&
               0 <= cur_node[1] + vec[1] && cur_node[1] + vec[1] < maze[0].size() &&
               !maze[cur_node[0] + vec[0]][cur_node[1] + vec[1]]) {
    
            cur_node[0] += vec[0];
            cur_node[1] += vec[1];
            ++dist;
            if (cur_node[0] == hole[0] &&
                cur_node[1] == hole[1]) {
                break;
            }
        }
        return {dist, {dir, cur_node}};
    }
    
    int hash(const vector<vector<int>>& maze, const vector<int>& node) {
        return node[0] * maze[0].size() + node[1];
    }

    template <class T>
    constexpr T &lvalue(T &&v) {
        return v;
    }
};
