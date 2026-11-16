# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def findMismatchedSegments(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: List[List[str]]
        """
        def f(i):
            return s1[i] != s2[i]

        result = []
        l = 0
        for i in xrange(len(s1)):
            l += 1
            if not (i+1 == len(s1) or f(i+1) != f(i)):
                continue
            if f(i):
                result.append([s1[i+1-l:i+1], s2[i+1-l:i+1]])
            l = 0
        return result
