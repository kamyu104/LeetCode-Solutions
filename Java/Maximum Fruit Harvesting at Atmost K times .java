class Solution {
    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        int left = 0, sum = 0, max = 0;

        for (int right = 0; right < fruits.length; right++) {
            sum += fruits[right][1];

            while (left <= right && minSteps(fruits[left][0], fruits[right][0], startPos) > k) {
                sum -= fruits[left][1];
                left++;
            }

            max = Math.max(max, sum);
        }

        return max;
    }

    private int minSteps(int left, int right, int start) {
        // Two paths: left first or right first
        int goLeft = Math.abs(start - left) + (right - left);
        int goRight = Math.abs(start - right) + (right - left);
        return Math.min(goLeft, goRight);
    }
}

