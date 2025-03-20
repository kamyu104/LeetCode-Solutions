# Time:  O(n^2 * r * logq), r = max(nums)
# Space: O(r)

# binary search, dp
class Solution(object):
    def minZeroArray(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: int
        """
        def binary_search(left, right, check):
            while left <= right:
                mid = left + (right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def check(l):
            def valid(arr, target):
                dp = [False]*(target+1)
                dp[0] = 1
                for i in xrange(len(arr)):
                    dp = [dp[j] or (j-arr[i] >= 0 and dp[j-arr[i]]) for j in xrange(target+1)]
                return dp[target]

            return all(valid([queries[j][2] for j in xrange(l) if queries[j][0] <= i <= queries[j][1]], nums[i]) for i in xrange(len(nums)))

        result = binary_search(0, len(queries), check)
        return result if result <= len(queries) else -1


# Time:  O(q * n * 2^n)
# Space: O(n * 2^n)
# dp
class Solution2(object):
    def minZeroArray(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: int
        """
        dp = [{0} for _ in xrange(len(nums))]
        for i, (l, r, v) in enumerate(queries):
            if all(nums[i] in dp[i] for i in xrange(len(dp))):
                return i
            for j in xrange(l, r+1):
                dp[j] |= set(x+v for x in dp[j])
        return len(queries) if all(nums[i] in dp[i] for i in xrange(len(dp))) else -1
