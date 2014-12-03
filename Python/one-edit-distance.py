# Time:  O(m + n)
# Space: O(1)
#
# Given two strings S and T, determine if they are both one edit distance apart.
#

class Solution:
    # @param s, a string
    # @param t, a string
    # @return a boolean
    def isOneEditDistance(self, s, t):
        m, n = len(s), len(t)
        if m > n:
            return self.isOneEditDistance(t, s)
        if n - m > 1:
            return False
        
        i, shift = 0, n - m
        while i < m and s[i] == t[i]:
            i += 1
        if shift == 0:
            i += 1
        while i < m and s[i] == t[i + shift]:
            i += 1
            
        return i == m
    
if __name__ == "__main__":
    print Solution().isOneEditDistance("teacher", "acher")