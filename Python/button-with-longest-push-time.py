# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def buttonWithLongestTime(self, events):
        """
        :type events: List[List[int]]
        :rtype: int
        """
        return -max((events[i][1]-(events[i-1][1] if i-1 >= 0 else 0), -events[i][0])for i in xrange(len(events)))[1]
