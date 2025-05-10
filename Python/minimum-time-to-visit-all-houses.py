# Time:  O(n + q)
# Space: O(n)

# prefix sum
class Solution(object):
    def minTotalTime(self, forward, backward, queries):
        """
        :type forward: List[int]
        :type backward: List[int]
        :type queries: List[int]
        :rtype: int
        """
        prefix1 = [0]*((2*len(forward)-1)+1)
        for i in xrange(2*len(forward)-1):
            prefix1[i+1] = prefix1[i]+forward[i%len(forward)]
        prefix2 = [0]*((2*len(backward)-1)+1)
        for i in xrange(2*len(backward)-1):
            prefix2[i+1] = prefix2[i]+backward[i%len(backward)]
        result = prev = 0
        for q in queries:
            if prev > q:
                result += min(prefix1[q+len(forward)]-prefix1[prev], prefix2[prev+1]-prefix2[q+1])
            else:
                result += min(prefix1[q]-prefix1[prev], prefix2[prev+len(forward)+1]-prefix2[q+1])
            prev = q
        return result
