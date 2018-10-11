# Time:  O(l)
# Space: O(l)

class Solution(object):
    def nearestPalindromic(self, n):
        """
        :type n: str
        :rtype: str
        """
        l = len(n)
        candidates = set((str(10**l + 1), str(10**(l - 1) - 1)))
        prefix = int(n[:(l + 1)/2])
        for i in map(str, (prefix-1, prefix, prefix+1)):
            candidates.add(i + [i, i[:-1]][l%2][::-1])
        candidates.discard(n)
        return min(candidates, key=lambda x: (abs(int(x) - int(n)), int(x)))

