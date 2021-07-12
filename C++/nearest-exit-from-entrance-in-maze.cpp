// Time:  O(m * n)
// Space: O(m + n)

// bi-bfs solution
class Solution {
private:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        static const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        static const char visited = '-';
        maze[entrance[0]][entrance[1]] = visited;
        unordered_set<pair<int, int>, PairHash<int>> left = {{entrance[0], entrance[1]}}, right;
        for (int r = 0; r < size(maze) - 1; ++r) {
            if (maze[r][0] == '.' && vector<int>({r, 0}) != entrance) {
                right.emplace(r, 0);
            }
        }
        for (int c = 0; c < size(maze[0]) - 1; ++c) {
            if (maze[size(maze) - 1][c] == '.' && vector<int>({int(size(maze)) - 1, c}) != entrance) {
                right.emplace(size(maze) - 1, c);
            }
        }
        for (int r = size(maze) - 1; r >= 1; --r) {
            if (maze[r][size(maze[0]) - 1] == '.' && vector<int>({r, int(size(maze[0])) - 1}) != entrance) {
                right.emplace(r, size(maze[0]) - 1);
            }
        }
        for (int c = size(maze[0]) - 1; c >= 1; --c) {
            if (maze[0][c] == '.' && vector<int>({0, c}) != entrance) {
                right.emplace(0, c);
            }
        }
        int steps = 0;
        while (!empty(left)) {
            for (const auto& [r, c] : left) {
                maze[r][c] = visited;
            }
            unordered_set<pair<int, int>, PairHash<int>> new_left;
            for (const auto& pos : left) {
                if (right.count(pos)) {
                    return steps;
                }
                for (const auto& [dr, dc] : directions) {
                    pair<int, int> nei = {pos.first + dr, pos.second + dc};
                    if (!(0 <= nei.first && nei.first < size(maze) &&
                          0 <= nei.second && nei.second < size(maze[0]) &&
                          maze[nei.first][nei.second] == '.')) {
                        continue;
                    }
                    new_left.emplace(nei);
                }
            }
            left = move(new_left);
            ++steps;
            if (size(left) > size(right)) {
                swap(left, right);
            }
        }
        return -1;
    }
};

// Time:  O(m * n)
// Space: O(m + n)
// bfs solution
class Solution2 {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        static const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        static const char visited = '-';
        maze[entrance[0]][entrance[1]] = visited;
        vector<pair<vector<int>, int>> q = {{entrance, 0}};
        while (!empty(q)) {
            vector<pair<vector<int>, int>> new_q;
            for (const auto& [curr, step] : q) {
                if (curr != entrance &&
                    (curr[0] == 0 || curr[0] == size(maze) - 1 ||
                     curr[1] == 0 || curr[1] == size(maze[0]) - 1)) {
                    return step;
                }
                for (const auto& [dr, dc] : directions) {
                    const auto nr = curr[0] + dr, nc = curr[1] + dc;
                    if (!(0 <= nr && nr < size(maze) &&
                          0 <= nc && nc < size(maze[0]) &&
                          maze[nr][nc] == '.')) {
                        continue;
                    }
                    maze[nr][nc] = visited;
                    new_q.emplace_back(vector<int>({nr, nc}), step + 1);
                }
            }
            q = move(new_q);
        }
        return -1;
    }
};
