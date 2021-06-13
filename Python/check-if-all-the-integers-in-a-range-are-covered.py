# Time:  O(n + r)
# Space: O(r)

# if r is small, this is better
class Solution(object):
    def isCovered(self, ranges, left, right):
        """
        :type ranges: List[List[int]]
        :type left: int
        :type right: int
        :rtype: bool
        """
        RANGE_SIZE = 50

        interval = [0]*(RANGE_SIZE+1)
        for l, r in ranges:
            interval[l-1] += 1
            interval[(r-1)+1] -= 1
        cnt = 0
        for i in xrange((right-1)+1):
            cnt += interval[i]
            if i >= left-1 and not cnt:
                return False
        return True


# Time:  O(nlogn)
# Space: O(1)
# if r is big, this is better
class Solution2(object):
    def isCovered(self, ranges, left, right):
        """
        :type ranges: List[List[int]]
        :type left: int
        :type right: int
        :rtype: bool
        """
        ranges.sort()
        for l, r in ranges:
            if l <= left <= r:
                left = r+1
        return left > right


# Time:  O(n * r)
# Space: O(1)
class Solution3(object):
    def isCovered(self, ranges, left, right):
        """
        :type ranges: List[List[int]]
        :type left: int
        :type right: int
        :rtype: bool
        """
        return all(any(l <= i <= r for l, r in ranges) for i in xrange(left, right+1))
