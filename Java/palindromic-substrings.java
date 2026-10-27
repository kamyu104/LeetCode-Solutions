// Time:  O(n^2)
// Space: O(1)

class Solution {
    public int countSubstrings(String s) {
        int substr = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            substr += expand(s,i,i);//odd len palindrome
            substr += expand(s,i , i + 1);//even len palindrome
        }
        return substr;
    }
    private int expand(String s, int left,int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            ++count;
            ++right;
            --left;
        }
        return count;
    }
}