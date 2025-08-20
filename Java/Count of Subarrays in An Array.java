class Solution {
    public int countCompleteSubarrays(int[] nums) {
        int cnt = 0;
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            set.add(nums[i]);
        }
        HashMap<Integer, Integer> map = new HashMap<>();
        int i = 0, j = 0;
        while (j < nums.length) {
            map.put(nums[j], map.getOrDefault(nums[j], 0) + 1);
            if (map.size() == set.size()) {
                cnt += nums.length - j;
                while (true) {
                    map.put(nums[i], map.get(nums[i]) - 1);
                    if (map.get(nums[i]) == 0) {
                        map.remove(nums[i++]);
                        break;
                    }
                    cnt += nums.length - j;
                    i++;
                }
            }
            j++;
        }
        return cnt;
    }
}