class Solution {
    public static int maxRemoval(int[] nums, int[][] queries) {
        int n = nums.length, q = queries.length;
        List<List<Integer>> qEnd = new ArrayList<>();
        for (int i = 0; i < n; i++) qEnd.add(new ArrayList<>());
        for (int[] query : queries) {
            qEnd.get(query[0]).add(query[1]);
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int[] cntQ = new int[n + 1];
        int dec = 0;

        for (int i = 0; i < n; i++) {
            dec += cntQ[i];
            for (int end : qEnd.get(i)) {
                pq.offer(end);
            }

            int x = nums[i];
            while (x > dec && !pq.isEmpty() && pq.peek() >= i) {
                int k = pq.poll();
                cntQ[k + 1]--;
                dec++;
            }

            if (x > dec) return -1;
        }

        return pq.size();
    }
}