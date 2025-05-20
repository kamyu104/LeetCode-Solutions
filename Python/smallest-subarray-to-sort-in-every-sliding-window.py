# Time:  O(n)
# Space: O(n)

# mono stack, two pointers
class Solution(object):
    def minSubarraySort(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        def count(nums):
            nxt, stk = [n]*n, []
            for i in reversed(xrange(n)):
                while not (not stk or nums[stk[-1]] >= nums[i]):
                    stk.pop()
                if stk:
                    nxt[i] = stk[-1]
                stk.append(i)
            result = []
            j, left = 0, -1
            for i in xrange(1, n):
                if nums[i] < nums[i-1]:
                    left = i
                if i < k-1:
                    continue
                j = max(j, i-(k-1))
                while not nxt[j] > left:
                    j = nxt[j]  # or j += 1
                result.append(max(i-nxt[j]+1, 0))
            return result

        n = len(nums)
        if k == 1:
            return [0]*(n-k+1)
        right = count(nums)
        for i in xrange((n+1)//2):
            nums[i], nums[~i] = -nums[~i], -nums[i]
        left = count(nums)
        return [max(k-left[~i]-right[i], 0) for i in xrange(n-k+1)]
