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
	hashmap := map[byte]int{}
	max := 0
	for i := range s {
		_, ok := hashmap[s[i]]
		if !ok {
			hashmap[s[i]] = i
			if len(hashmap) > max {
				max = len(hashmap)
			}
		} else {
			// remove repeated
			oldI := hashmap[s[i]]
			hashmap[s[i]] = i

			for key, value := range hashmap {
				if value < oldI {
					delete(hashmap, key)
				}
			}
		}
	}
	return max
}
