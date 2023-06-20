# Time:  O(n)
# Space: O(n)

# mono stack, difference array, prefix sum
class Solution(object):
    def minCost(self, nums, x):
        """
        :type nums: List[int]
        :type x: int
        :rtype: int
        """
        def accumulate(a):
            for i in xrange(len(a)-1):
                a[i+1] += a[i]
            return a

        i = min(xrange(len(nums)), key=lambda x: nums[x])
        nums = nums[i:]+nums[:i]
        left, right = [-1]*len(nums), [len(nums)]*len(nums)
        stk = []
        for i in xrange(len(nums)):
            while stk and nums[stk[-1]] > nums[i]:
                right[stk.pop()] = i
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        diff2 = [0]*(len(nums)+1)
        diff2[0] = (+1)*sum(nums)             # diff1[k] has sum((+1)*nums[i] for i in xrange(len(nums))) for k >= 0
        diff2[1] = x                          # diff1[k] has x for k >= 1
        diff2[-1] += (-1)*nums[0]             # diff1[len(nums)] has 0*nums[0]
        for i in xrange(1, len(nums)):
            l, r = i-left[i], right[i]-i
            diff2[min(l, r)] += (-1)*nums[i]  # diff1[k] has 0*nums[i] for min(l, r) <= k < max(l, r)
            diff2[max(l, r)] += (-1)*nums[i]  # diff1[k] has (-1)*nums[i] for max(l, r) <= k < l+r
            diff2[l+r] += (+1)*nums[i]        # diff1[k] has 0*nums[i] to for k >= l+r
        return min(accumulate(accumulate(diff2)))


# Time:  O(nlogn)
# Space: O(n)
import collections


# binary search, mono deque
class Solution2(object):
    def minCost(self, nums, x):
        """
        :type nums: List[int]
        :type x: int
        :rtype: int
        """
        def cost(k):
            w = k+1
            result = x*k
            dq = collections.deque()
            for i in xrange(len(nums)+w-1):
                if dq and i-dq[0] == w:
                    dq.popleft()
                while dq and nums[dq[-1]%len(nums)] >= nums[i%len(nums)]:
                    dq.pop()
                dq.append(i)
                if i >= w-1:
                    result += nums[dq[0]%len(nums)]
            return result

        def check(x):
            return cost(x) <= cost(x+1)

        left, right = 0, len(nums)
        while left <= right:
            mid = left + (right-left)//2
            if check(mid):
                right = mid-1
            else:
                left = mid+1
        return cost(left)


# Time:  O(n^2)
# Space: O(n)
# brute force
class Solution3(object):
    def minCost(self, nums, x):
        """
        :type nums: List[int]
        :type x: int
        :rtype: int
        """
        result = [x*k for k in xrange(len(nums)+1)]
        for i in xrange(len(nums)):
            curr = nums[i]
            for k in xrange(len(result)):
                curr = min(curr, nums[(i+k)%len(nums)])
                result[k] += curr
        return min(result)
