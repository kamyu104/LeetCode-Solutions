# Time:  O(n + (n + logr) + nlog(logr) + nlogn) = O(nlogn), assumed log(x) takes O(1) time
# Space: O(n)

import math


# sort, two pointers, sliding window, fast exponentiation
class Solution(object):
    def getFinalState(self, nums, k, multiplier):
        """
        :type nums: List[int]
        :type k: int
        :type multiplier: int
        :rtype: List[int]
        """
        EPS = 1e-15
        def count(x, target):
            return int(target-x+EPS)

        if multiplier == 1:
            return nums
        vals = sorted((log(x)/log(multiplier), i) for i, x in enumerate(nums))
        left = 0
        for right in xrange(1, (int(vals[-1][0])+1)+1):
            while left < len(vals) and count(vals[left][0], right) >= 1:
                left += 1
            if k-left < 0:
                right -= 1
                break
            k -= left
        for idx, (x, i) in enumerate(vals):
            c = count(x, right)
            if c <= 0:
                break
            nums[i] *= pow(multiplier, c)
        q, r = divmod(k, len(nums))
        m = pow(multiplier, q)
        result = [0]*len(nums)
        for idx, (x, i) in enumerate(sorted((x, i) for i, x in enumerate(nums))):
            result[i] = x*m*(multiplier if idx < r else 1)
        return result


# Time:  O(n + min(n, k) * log(logr) + nlog(logr) + nlogn) = O(nlogr), assumed log(x) takes O(1) time
# Space: O(n)
import math


# binary search, sort, fast exponentiation
class Solution2(object):
    def getFinalState(self, nums, k, multiplier):
        """
        :type nums: List[int]
        :type k: int
        :type multiplier: int
        :rtype: List[int]
        """
        EPS = 1e-15
        def binary_search_right(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if not check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return right

        def count(x, target):
            return int(target-x+EPS)

        def check(target):
            result = 0
            for x, i in vals:
                c = count(x, target)
                if c <= 0:
                    break
                result += c
            return result <= k

        if multiplier == 1:
            return nums
        vals = sorted((log(x)/log(multiplier), i) for i, x in enumerate(nums))
        target = binary_search_right(1, int(vals[-1][0])+1, check)
        for idx, (x, i) in enumerate(vals):
            c = count(x, target)
            if c <= 0:
                break
            k -= c
            nums[i] *= pow(multiplier, c)
        q, r = divmod(k, len(nums))
        m = pow(multiplier, q)
        result = [0]*len(nums)
        for idx, (x, i) in enumerate(sorted((x, i) for i, x in enumerate(nums))):
            result[i] = x*m*(multiplier if idx < r else 1)
        return result


# Time:  O(min(nlogr, k) * logn + nlogn) = O(nlogn * logr)
# Space: O(n)
import heapq


# heap, sort, fast exponentiation
class Solution3(object):
    def getFinalState(self, nums, k, multiplier):
        """
        :type nums: List[int]
        :type k: int
        :type multiplier: int
        :rtype: List[int]
        """
        if multiplier == 1:
            return nums
        min_heap = [(x, i) for i, x in enumerate(nums)]
        heapq.heapify(min_heap)
        mx = max(nums)
        for k in reversed(xrange(1, k+1)):
            if min_heap[0][0]*multiplier > mx:
                break
            x, i = heapq.heappop(min_heap)
            heapq.heappush(min_heap, (x*multiplier, i))
        else:
            k = 0
        vals = sorted(min_heap)
        q, r = divmod(k, len(nums))
        m = pow(multiplier, q)
        result = [0]*len(nums)
        for idx, (x, i) in enumerate(vals):
            result[i] = x*m*(multiplier if idx < r else 1)
        return result


# Time:  O(n + klogn)
# Space: O(n)
import heapq


# simulation, heap
class Solution4(object):
    def getFinalState(self, nums, k, multiplier):
        """
        :type nums: List[int]
        :type k: int
        :type multiplier: int
        :rtype: List[int]
        """
        if multiplier == 1:
            return nums
        min_heap = [(x, i) for i, x in enumerate(nums)]
        heapq.heapify(min_heap)
        for _ in xrange(k):
            i = heapq.heappop(min_heap)[1]
            nums[i] *= multiplier
            heapq.heappush(min_heap, (nums[i], i))
        return nums


# Time:  O(k * n)
# Space: O(1)
# simulation
class Solution5(object):
    def getFinalState(self, nums, k, multiplier):
        """
        :type nums: List[int]
        :type k: int
        :type multiplier: int
        :rtype: List[int]
        """
        if multiplier == 1:
            return nums
        for _ in xrange(k):
            i = min(xrange(len(nums)), key=lambda i: nums[i])
            nums[i] *= multiplier
        return nums
