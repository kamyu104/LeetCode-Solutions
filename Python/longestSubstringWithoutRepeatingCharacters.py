# Time:  O(n)
# Space: O(1)
#
# Given a string, find the length of the longest substring without repeating characters.
# For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
# For "bbbbb" the longest substring is "b", with the length of 1.
#

class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        longest, start, visited = 0, 0, [False for i in xrange(256)]
        for i, char in enumerate(s):
            if visited[ord(char)]:
                while char != s[start]:
                    visited[ord(s[start])] = False
                    start += 1
                start += 1
            else:
                visited[ord(char)] = True
            longest = max(longest, i - start + 1)
        return longest

if __name__ == "__main__":
    print Solution().lengthOfLongestSubstring("abcabcbb")