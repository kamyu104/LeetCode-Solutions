# Time:  O(nlogn)
# Space: O(n)

# sort
class Solution(object):
    def countOperationsToEmptyArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        idxs = range(len(nums))
        idxs.sort(key=lambda x: nums[x])
        return len(idxs)+sum(len(idxs)-(i+1) for i in xrange(len(idxs)-1) if idxs[i] > idxs[i+1])


# Time:  O(nlogn)
# Space: O(n)
# sort, bit, fenwick tree
class Solution2(object):
    def countOperationsToEmptyArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
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
        
        bit = BIT(len(nums))
        idxs = range(len(nums))
        idxs.sort(key=lambda x: nums[x])
        result = len(nums)
        prev = -1
        for i in idxs:
            if prev == -1:
                result += i
            elif prev < i:
                result += (i-prev)-(bit.query(i)-bit.query(prev-1))
            else:
                result += ((len(nums)-1)-bit.query(len(nums)-1))-((prev-i)-(bit.query(prev)-bit.query(i-1)))
            bit.add(i, 1)
            prev = i
        return result
