# Time:  O(nlogn)
# Space: O(1)

# Erdős–Gallai theorem, sort, prefix sum, two pointers
class Solution(object):
    def simpleGraphExists(self, degrees):
        """
        :type degrees: List[int]
        :rtype: bool
        """
        # reference: https://en.wikipedia.org/wiki/Erd%C5%91s%E2%80%93Gallai_theorem
        if sum(degrees)%2:
            return False
        degrees.sort(reverse=True)
        prefix = 0
        suffix1 = sum(degrees)
        suffix2 = 0
        i = len(degrees)-1
        for k in xrange(1, len(degrees)+1):
            prefix += degrees[k-1]
            suffix1 -= degrees[k-1]
            while i >= 0 and degrees[i] < k:
                suffix2 += degrees[i]
                i -= 1
            if not prefix <= k*(k-1)+((i-k+1)*k+suffix2 if i-k+1 > 0 else suffix1):
                return False
        return True

