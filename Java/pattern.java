class Solution {
    public boolean find132pattern(int[] nums) {
        int n = nums.length;
        int[] uptoIdxMin = new int[n];
        uptoIdxMin[0] = nums[0];
        for (int i = 1; i < n; i++) {
            uptoIdxMin[i] = Math.min(uptoIdxMin[i - 1], nums[i]);
        }
        Stack<Integer> stack = new Stack<>();
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > uptoIdxMin[i]) {
                while (!stack.isEmpty() && stack.peek() <= uptoIdxMin[i]) {
                    stack.pop();
                }
                if (!stack.isEmpty() && stack.peek() < nums[i]) {
                    return true;
                }
                stack.push(nums[i]);
            }
        }
        return false;
    }
}
