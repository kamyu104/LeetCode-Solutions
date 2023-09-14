# Time:  O(1)
# Space: O(1)

import collections


# freq table
class Solution(object):
    def canBeEqual(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        return all(collections.Counter(s1[j] for j in xrange(i, len(s1), 2)) == collections.Counter(s2[j] for j in xrange(i, len(s2), 2)) for i in xrange(2))


# Time:  O(1)
# Space: O(1)
# brute force
class Solution2(object):
    def canBeEqual(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        return (((s1[0] == s2[0] and s1[2] == s2[2]) or (s1[0] == s2[2] and s1[2] == s2[0])) and
                ((s1[1] == s2[1] and s1[3] == s2[3]) or (s1[1] == s2[3] and s1[3] == s2[1])))
