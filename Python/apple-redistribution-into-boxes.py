# Time:  O(nlogn)
# Space: O(1)

# sort, greedy
class Solution(object):
    def minimumBoxes(self, apple, capacity):
        """
        :type apple: List[int]
        :type capacity: List[int]
        :rtype: int
        """
        capacity.sort(reverse=True)
        total = sum(apple)
        for i in xrange(len(capacity)):
            total -= capacity[i]
            if total <= 0:
                return i+1
        return -1
