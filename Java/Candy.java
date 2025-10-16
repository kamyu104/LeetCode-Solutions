class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int[] cand = new int[n];
        Arrays.fill(cand, 1); // Step 1: Each child gets at least one candy

        // Step 2: Left to right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                cand[i] = cand[i - 1] + 1;
            }
        }

        // Step 3: Right to left pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && cand[i] <= cand[i + 1]) {
                cand[i] = cand[i + 1] + 1;
            }
        }

        // Step 4: Sum all candies
        int ans = 0;
        for (int c : cand) {
            ans += c;
        }

        return ans;
    }
}
