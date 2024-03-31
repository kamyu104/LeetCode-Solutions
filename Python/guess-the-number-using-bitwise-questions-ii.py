# Time:  O(logr)
# Space: O(1)

# bit manipulation
class Solution(object):
    def findNumber(self):
        """
        :rtype: int
        """
        BIT_COUNT = 30
        result = 0
        prev = commonBits(0)
        for i in xrange(BIT_COUNT):
            curr = commonBits(1<<i)
            if curr-prev == 1:
                result |= 1<<i
            prev = curr
        return result


# Time:  O(logr)
# Space: O(1)
# bit manipulation
class Solution2(object):
    def findNumber(self):
        """
        :rtype: int
        """
        BIT_COUNT = 30
        return reduce(lambda accu, i: accu|(1<<i if commonBits(1<<i)-commonBits(1<<i) == 1 else 0), xrange(BIT_COUNT), 0)
