class Solution {

    public List<String> removeAnagrams(String[] words) {
        List<String> res = new ArrayList<>();
        res.add(words[0]); // result array
        int n = words.length;
        for (int i = 1; i < n; i++) {
            if (!compare(words[i], words[i - 1])) {
                res.add(words[i]);
            }
        }
        return res;
    }

    // determine if two words are anagrams
    private boolean compare(String word1, String word2) {
        int[] freq = new int[26];
        for (char ch : word1.toCharArray()) {
            freq[ch - 'a']++;
        }
        for (char ch : word2.toCharArray()) {
            freq[ch - 'a']--;
        }
        for (int x : freq) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }
}
