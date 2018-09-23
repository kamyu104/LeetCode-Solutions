// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        const int n = board.size();
        unordered_map<int, int> lookup;
        lookup[1] = 0;
        queue<int> q({1});
        while (!q.empty()) {
            const auto s = q.front(); q.pop();
            if (s == n * n) {
                return lookup[s];
            }
            for (int i = s + 1; i < min(s + 6, n * n) + 1; ++i) {
                int r, c;
                tie(r, c) = coordinate(n, i);
                int s2 = i;
                if (board[r][c] != -1) {
                    s2 = board[r][c];
                }
                if (!lookup.count(s2)) {
                    lookup[s2] = lookup[s] + 1;
                    q.emplace(s2);
                }
            }
        }
        return -1;
    }

private:
    pair<int, int> coordinate(int n, int s) {
        const int a = (s - 1) / n;
        const int b = (s - 1) % n;
        const int r = n - 1 - a;
        const int c = (r % 2 != n % 2) ? b : n - 1 - b;
        return {r, c};
    }
};
