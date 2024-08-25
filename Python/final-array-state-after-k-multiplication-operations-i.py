# Time:  O(min(nlogr, k) * logn + nlogn)
# Space: O(n)

import heapq


# heap, sort, fast exponentiation
class Solution(object):
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
        while k:
            if min_heap[0][0]*multiplier > mx:
                break
            x, i = heapq.heappop(min_heap)
            heapq.heappush(min_heap, (x*multiplier, i))
            k -= 1
        vals = sorted(min_heap)
        q, r = divmod(k, len(nums))
        m = pow(multiplier, q)
        result = [0]*len(nums)
        for idx, (x, i) in enumerate(vals):
            result[i] = x*m*(multiplier if idx < r else 1)
        return result


# Time:  O(min(nlogr, k) * logr + nlogn)
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
        def binary_search_right(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if not check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return right

        def count(x, target):
            cnt = int(math.floor((math.log(target)-math.log(x))/math.log(multiplier)))
            if x*pow(multiplier, cnt+1) <= target:
                cnt += 1
            return cnt

        def check(target):
            result = 0
            for x, _ in vals:
                if x >= target:
                    break
                c = count(x, target)
                if c == 0:
                    break
                result += c
            return result <= k

        if multiplier == 1:
            return nums
        vals = sorted([x, i] for i, x in enumerate(nums))
        target = binary_search_right(1, vals[-1][0], check)
        for idx, (x, i) in enumerate(vals):
            if x >= target:
                break
            cnt = count(x, target)
            k -= cnt
            vals[idx][0] *= pow(multiplier, count(x, target))
        vals.sort()
        q, r = divmod(k, len(nums))
        m = pow(multiplier, q)
        result = [0]*len(nums)
        for idx, (x, i) in enumerate(vals):
            result[i] = x*m*(multiplier if idx < r else 1)
        return result


# Time:  O(klogn)
# Space: O(n)
import heapq


# heap, sort
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
        while k:
            x, i = heapq.heappop(min_heap)
            heapq.heappush(min_heap, (x*multiplier, i))
            k -= 1
        result = [0]*len(nums)
        for x, i in min_heap:
            result[i] = x
        return result
