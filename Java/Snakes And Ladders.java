class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        boolean[] visited = new boolean[n * n + 1];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{1, 0}); // {square number, number of moves}
        visited[1] = true;

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int square = curr[0];
            int moves = curr[1];

            for (int i = 1; i <= 6; i++) {
                int next = square + i;
                if (next > n * n) continue;

                int[] pos = getCoordinates(next, n);
                int r = pos[0], c = pos[1];

                if (board[r][c] != -1) {
                    next = board[r][c];
                }

                if (next == n * n) {
                    return moves + 1;
                }

                if (!visited[next]) {
                    visited[next] = true;
                    queue.offer(new int[]{next, moves + 1});
                }
            }
        }

        return -1; // unreachable
    }

    // Converts 1-based square number to (row, col) in board
    private int[] getCoordinates(int num, int n) {
        int r = (n - 1) - (num - 1) / n;
        int c = (num - 1) % n;
        if (((n - 1 - r) % 2) == 1) {
            c = n - 1 - c;
        }
        return new int[]{r, c};
    }
}
