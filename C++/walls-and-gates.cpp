// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[0].size(); ++j) {
                if (rooms[i][j] == 0) {
                    queue<tuple<int, int, int>> q;
                    q.emplace(make_tuple(i + 1, j, 1));
                    q.emplace(make_tuple(i - 1, j, 1));
                    q.emplace(make_tuple(i, j + 1, 1));
                    q.emplace(make_tuple(i, j - 1, 1));
                    while (!q.empty()) {
                        int ii, jj, dist;
                        tie(ii, jj, dist) = q.front();
                        q.pop();
                        if (ii < 0 || jj < 0 || ii >= rooms.size() ||
                            jj >= rooms[0].size() || rooms[ii][jj] <= dist) {
                            continue;
                        }
                        rooms[ii][jj] = dist;
                        q.emplace(make_tuple(ii + 1, jj, dist + 1));
                        q.emplace(make_tuple(ii - 1, jj, dist + 1));
                        q.emplace(make_tuple(ii, jj + 1, dist + 1));
                        q.emplace(make_tuple(ii, jj - 1, dist + 1));
                    }
                }
            }
        }
    }
};
