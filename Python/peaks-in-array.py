# Time:  O(n + qlogn)
# Space: O(n)

# bit, fenwick tree
class Solution(object):
    def countOfPeaks(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        class BIT(object):  # 0-indexed.
            def __init__(self, nums):
                self.__bit = [0]*(len(nums)+1)  # Extra one for dummy node.
                for i in xrange(1, len(self.__bit)):
                    self.__bit[i] = nums[i-1] + self.__bit[i-1]
                for i in reversed(xrange(1, len(self.__bit))):
                    last_i = i - (i & -i)
                    self.__bit[i] -= self.__bit[last_i]

            def add(self, i, val):
                i += 1  # Extra one for dummy node.
                while i < len(self.__bit):
                    self.__bit[i] += val
                    i += (i & -i)

            def query(self, i):
                i += 1  # Extra one for dummy node.
                ret = 0
                while i > 0:
                    ret += self.__bit[i]
                    i -= (i & -i)
                return ret

        def check(i):
            return nums[i-1] < nums[i] > nums[i+1]

        def update(x, d):
            for i in xrange(max(x-1, 1), min((x+1)+1, len(nums)-1)):
                if check(i):
                    bit.add(i, d)

        bit = BIT([int(1 <= i <= len(nums)-2 and check(i)) for i in xrange(len(nums))])
        result = []
        for t, x, y in queries:
            if t == 1:
                result.append(bit.query(y-1)-bit.query((x+1)-1) if y-1 >= x+1 else 0)
                continue
            update(x, -1)
            nums[x] = y
            update(x, +1)
        return result


# Time:  O(nlogn + qlogn)
# Space: O(n)
# bit, fenwick tree
class Solution2(object):
    def countOfPeaks(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        class BIT(object):  # 0-indexed.
            def __init__(self, n):
                self.__bit = [0]*(n+1)  # Extra one for dummy node.

            def add(self, i, val):
                i += 1  # Extra one for dummy node.
                while i < len(self.__bit):
                    self.__bit[i] += val
                    i += (i & -i)

            def query(self, i):
                i += 1  # Extra one for dummy node.
                ret = 0
                while i > 0:
                    ret += self.__bit[i]
                    i -= (i & -i)
                return ret

        def check(i):
            return nums[i-1] < nums[i] > nums[i+1]

        def update(x, d):
            for i in xrange(max(x-1, 1), min((x+1)+1, len(nums)-1)):
                if check(i):
                    bit.add(i, d)

        bit = BIT(len(nums))
        for i in xrange(1, len(nums)-1):
            if check(i):
                bit.add(i, +1)
        result = []
        for t, x, y in queries:
            if t == 1:
                result.append(bit.query(y-1)-bit.query((x+1)-1) if y-1 >= x+1 else 0)
                continue
            update(x, -1)
            nums[x] = y
            update(x, +1)
        return result
