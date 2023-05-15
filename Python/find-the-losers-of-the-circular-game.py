# Time:  O(n)
# Space: O(n)

# hash table, simulation
class Solution(object):
    def circularGameLosers(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        lookup = [False]*n
        idx = 0
        for i in xrange(n):
            if lookup[idx]:
                break
            lookup[idx] = True
            idx = (idx+(i+1)*k)%n
        return [i+1 for i in xrange(n) if not lookup[i]]
