# Time:  O(n^2)
# Space: O(n)
#
# Given a string s and a dictionary of words dict, 
# determine if s can be segmented into a space-separated sequence of one or more dictionary words.
# 
# For example, given
# s = "leetcode",
# dict = ["leet", "code"].
# 
# Return true because "leetcode" can be segmented as "leet code".
#

class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a boolean
    def wordBreak(self, s, dict):
        possible = []
        for i in xrange(len(s)):
            if s[:i + 1] in dict:
                possible.append(True)
            else:
                found = False
                for j in xrange(i):
                    if possible[j] == True and s[j + 1: i + 1] in dict:
                        found = True
                        break
                possible.append(found)
                
        return possible[len(s) - 1]

if __name__ == "__main__":
    print Solution().wordBreak("leetcode", ["leet", "code"])