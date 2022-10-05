# Time:  O(nlogn)
# Space: O(n)

from sortedcontainers import SortedList
import itertools


# sorted list, binary search
class Solution(object):
    def numberOfPairs(self, nums1, nums2, diff):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type diff: int
        :rtype: int
        """
        sl = SortedList()
        result = 0
        for x, y in itertools.izip(nums1, nums2):
            result += sl.bisect_right((x-y)+diff)
            sl.add(x-y)
        return result

    
# Time:  O(nlogn)
# Space: O(n)
import itertools
import bisect


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


# bit, fenwick tree, coordinate compression
class Solution2(object):
    def numberOfPairs(self, nums1, nums2, diff):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type diff: int
        :rtype: int
        """
        sorted_nums = sorted(set(x-y for x, y in itertools.izip(nums1, nums2)))
        num_to_idx = {x:i for i, x in enumerate(sorted_nums)}
        result = 0
        bit = BIT(len(num_to_idx))
        for x, y in itertools.izip(nums1, nums2):
            result += bit.query(bisect.bisect_right(sorted_nums, (x-y)+diff)-1)
            bit.add(num_to_idx[x-y], 1)
        return result


# Time:  O(nlogn)
# Space: O(n)
import itertools


# merge sort, two pointers
class Solution3(object):
    def numberOfPairs(self, nums1, nums2, diff):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type diff: int
        :rtype: int
        """
        def merge_sort(nums, left, right, result):
            if left == right:
                return
            mid = left+(right-left)//2
            merge_sort(nums, left, mid, result)
            merge_sort(nums, mid+1, right, result)
            r = mid+1
            for l in xrange(left, mid+1):
                while r < right+1 and nums[l]-nums[r] > diff:
                    r += 1
                result[0] += right-r+1
            tmp = []
            l, r = left, mid+1
            while l < mid+1 or r < right+1:
                if r >= right+1 or (l < mid+1 and nums[l] <= nums[r]):
                    tmp.append(nums[l])
                    l += 1
                else:
                    tmp.append(nums[r])
                    r += 1
            nums[left:right+1] = tmp

        nums = [x-y for x, y in itertools.izip(nums1, nums2)]
        result = [0]
        merge_sort(nums, 0, len(nums)-1, result)
        return result[0]
