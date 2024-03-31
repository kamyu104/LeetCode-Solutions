# Time:  O(n)
# Space: O(n)

# prefix sum
class Solution(object):
    def minimumLevels(self, possible):
        """
        :type possible: List[int]
        :rtype: int
        """
        prefix = [0]*(len(possible)+1)
        for i in xrange(len(possible)):
            prefix[i+1] = prefix[i]+(+1 if possible[i] else -1)
        return next((i+1 for i in xrange(len(possible)-1) if prefix[i+1] > prefix[-1]-prefix[i+1]), -1)
