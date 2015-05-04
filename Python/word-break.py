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
    # @param s: A string s
    # @param dict: A dictionary of words dict
    def wordSegmentation(self, s, dict):
        if not s:
            return True
            
        cnt = {}
        for w in dict:
            for c in w:
                if c not in cnt:
                    cnt[c] = 0
                cnt[c] += 1
        for c in s:
            if c not in cnt:
                return False
                
        n = len(s)
        possible = [False for _ in xrange(n)]
        for i in xrange(n):
            for j in reversed(xrange(i + 1)):
                if (j == 0 or possible[j-1]) and s[j:i+1] in dict:
                    possible[i] = True
                    break
                
        return possible[n-1]

# slower
class Solution2:
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
