# Time:  O(n1 + n2 + ...)
# Space: O(1)
#
# Write a function to find the longest common prefix string amongst an array of strings.
#

class Solution:
    # @return a string
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
        longest = strs[0]
        for string in strs[1:]:
            i = 0
            while i < len(string) and i < len(longest) and string[i] == longest[i]:
                i += 1
            longest = longest[:i]
        return longest
    
if __name__ == "__main__":
    print Solution().longestCommonPrefix(["hello", "heaven", "heavy"])
            
