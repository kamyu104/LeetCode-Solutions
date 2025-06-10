class Solution {
    public int maxDifference(String s) {
        Map<Character, Integer> freq = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }
        int maxOdd = -1;
        int minEven = Integer.MAX_VALUE;
        for (int f : freq.values()) {
            if ((f & 1) == 1) maxOdd = Math.max(maxOdd, f);
            else minEven = Math.min(minEven, f);
        }
        if (maxOdd == -1 || minEven == Integer.MAX_VALUE) return -1;
        return maxOdd - minEven;
    }
}
