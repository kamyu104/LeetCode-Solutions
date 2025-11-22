package leetcode

// Given a string, find the length of the longest substring without repeating characters.
//
// Examples:
// Given "abcabcbb", the answer is "abc", which the length is 3.
// Given "bbbbb", the answer is "b", with the length of 1.
// Given "pwwkew", the answer is "wke", with the length of 3.
// Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
func lengthOfLongestSubstring(s string) int {
	maxLen := 0
	m := map[byte]int{}
	for i, j := 0, 0; j < len(s); j++ {
		idx, ok := m[s[j]]
		if ok && idx >= i {
			i = idx + 1
		}
		if maxLen < j-i+1 {
			maxLen = j - i + 1
		}
		m[s[j]] = j
	}
	return maxLen
}
