import java.util.*;

public class Solution {

    public int minTimeToReach(int[][] moveTime) {

        int n = moveTime.length;

        int m = moveTime[0].length;

        int[][] bestTime = new int[n][m];

        for (int[] row : bestTime) {

            Arrays.fill(row, Integer.MAX_VALUE);

        }

        int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));

        pq.offer(new int[]{0, 0, 0, 0}); // time, i, j, nextMoveTime

        while (!pq.isEmpty()) {

            int[] curr = pq.poll();

            int time = curr[0], i = curr[1], j = curr[2], nextMoveTime = curr[3];

            if (time >= bestTime[i][j]) continue;

            bestTime[i][j] = time;

            if (i == n - 1 && j == m - 1) return time;

            for (int[] d : directions) {

                int x = i + d[0], y = j + d[1];

                if (x >= 0 && x < n && y >= 0 && y < m) {

                    int wait = moveTime[x][y];

                    int futureMove = nextMoveTime == 1 ? 2 : 1;

                    int nextTime = wait > time ? wait + futureMove : time + futureMove;

                    if (i == 0 && j == 0 && wait <= time) {

                        nextTime = wait + futureMove;

                    }

                    if (nextTime < bestTime[x][y]) {

                        pq.offer(new int[]{nextTime, x, y, futureMove});

                    }

                }

            }

        }

        return -1; // Should never reach

    }

}
    
