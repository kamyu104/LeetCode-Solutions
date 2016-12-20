# Time:  O(s1 * n1)
# Space: O(s2)

# Define S = [s,n] as the string S which consists of n connected strings s.
# For example, ["abc", 3] ="abcabcabc".
#
# On the other hand, we define that string s1 can be obtained from string s2 
# if we can remove some characters from s2 such that it becomes s1.
# For example, “abc” can be obtained from “abdbec” based on our definition, but it can not be obtained from “acbbe”.
#
# You are given two non-empty strings s1 and s2 (each at most 100 characters long)
# and two integers 0 ≤ n1 ≤ 106 and 1 ≤ n2 ≤ 106. Now consider the strings S1 and S2,
# where S1=[s1,n1] and S2=[s2,n2]. Find the maximum integer M such that [S2,M] can be obtained from S1.
#
# Example:
#
# Input:
# s1="acb", n1=4
# s2="ab", n2=2
#
# Return:
# 2

class Solution(object):
    def getMaxRepetitions(self, s1, n1, s2, n2):
        """
        :type s1: str
        :type n1: int
        :type s2: str
        :type n2: int
        :rtype: int
        """
        repeat_count = [0] * (len(s2)+1)
        lookup = {}
        j, count = 0, 0
        for k in xrange(1, n1+1):
            for i in xrange(len(s1)):
                if s1[i] == s2[j]:
                    j = (j + 1) % len(s2)
                    count += (j == 0)
            
            if j in lookup:   # cyclic
                i = lookup[j]
                prefix_count = repeat_count[i]
                pattern_count = (count - repeat_count[i]) * ((n1 - i) // (k - i))
                suffix_count = repeat_count[i + (n1 - i) % (k - i)] - repeat_count[i]
                return (prefix_count + pattern_count + suffix_count) / n2
            lookup[j] = k
            repeat_count[k] = count
        
        return repeat_count[n1] / n2  # not cyclic iff n1 <= s2
