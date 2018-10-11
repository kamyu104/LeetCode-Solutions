# Time:  O(l * n^2)
# Space: O(1)

class Solution(object):
    def findLUSlength(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        def isSubsequence(a, b):
            i = 0
            for j in xrange(len(b)):
                if i >= len(a):
                    break
                if a[i] == b[j]:
                    i += 1
            return i == len(a)

        strs.sort(key=len, reverse=True)
        for i in xrange(len(strs)):
            all_of = True
            for j in xrange(len(strs)):
                if len(strs[j]) < len(strs[i]):
                    break
                if i != j and isSubsequence(strs[i], strs[j]):
                    all_of = False
                    break
            if all_of:
                return len(strs[i])
        return -1

