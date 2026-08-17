# Time:  O(r), r = len(requests)
# Space: O(1)

# array
class Solution(object):
    def elevatorRequests(self, n, requests):
        """
        :type n: int
        :type requests: List[int]
        :rtype: int
        """
        return requests[0]+sum(abs(requests[i+1]-requests[i]) for i in xrange(len(requests)-1))
