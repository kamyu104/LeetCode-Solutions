class Solution {

    private static final int[][] DIRS = {
        { 1, 1 },
        { 1, -1 },
        { -1, -1 },
        { -1, 1 },
    };
    private int[][][][] memo;
    private int[][] grid;
    private int m, n;

    public int lenOfVDiagonal(int[][] grid) {
        this.grid = grid;
        this.m = grid.length;
        this.n = grid[0].length;
        this.memo = new int[m][n][4][2];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    Arrays.fill(memo[i][j][k], -1);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int direction = 0; direction < 4; direction++) {
                        res = Math.max(res, dfs(i, j, direction, true, 2) + 1);
                    }
                }
            }
        }
        return res;
    }

    private int dfs(int cx, int cy, int direction, boolean turn, int target) {
        int nx = cx + DIRS[direction][0];
        int ny = cy + DIRS[direction][1];
        /* If it goes beyond the boundary or the next node's value is not the target value, then return */
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != target) {
            return 0;
        }

        int turnInt = turn ? 1 : 0;
        if (memo[nx][ny][direction][turnInt] != -1) {
            return memo[nx][ny][direction][turnInt];
        }

        /* Continue walking in the original direction. */
        int maxStep = dfs(nx, ny, direction, turn, 2 - target);
        if (turn) {
            /* Clockwise rotate 90 degrees turn */
            maxStep = Math.max(
                maxStep,
                dfs(nx, ny, (direction + 1) % 4, false, 2 - target)
            );
        }
        memo[nx][ny][direction][turnInt] = maxStep + 1;
        return maxStep + 1;
    }
}
