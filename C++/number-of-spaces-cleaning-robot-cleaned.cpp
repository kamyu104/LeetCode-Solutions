// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    int numberOfCleanRooms(vector<vector<int>>& room) {
        static const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int result = 0, r = 0, c = 0, d = 0;
        while (!(room[r][c] & (1 << (d + 1)))) {
            result += (room[r][c] >> 1) == 0;
            room[r][c] |= (1 << (d + 1));
            const auto& [dr, dc] = directions[d];
            const int nr = r + dr, nc = c + dc;
            if ((0 <= nr && nr < size(room)) && (0 <= nc && nc < size(room[0])) && !(room[nr][nc] & 1)) {
                r = nr, c = nc;
            } else {
                d = (d + 1) % 4;
            }
        }
        return result;
    }
};
