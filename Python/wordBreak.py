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
        n = len(s)
        possible = [False for _ in xrange(n)]
        for i in xrange(n):
            if s[:i+1] in dict:
                possible[i] = True
            for j in xrange(i):
                if possible[j] and s[j+1:i+1] in dict:
                    possible[i] = True
                    break
                
        return possible[n-1]
    
if __name__ == "__main__":
    print Solution().wordBreak("leetcode", ["leet", "code"])