# Time:  O(n * m * logr), r = max(nums)
# Space: O(n * m * logr)

import collections


# dp, mono deque, two pointers
class Solution(object):
    def minimumValueSum(self, nums, andValues):
        """
        :type nums: List[int]
        :type andValues: List[int]
        :rtype: int
        """
        INF = float("inf")
        L = max(nums).bit_length()
        def update(cnt, x, l, d):
            for i in xrange(L):
                if x&(1<<i):
                    cnt[i] += d
            return reduce(lambda accu, i: accu|(1<<i), (i for i  in xrange(L) if cnt[i] == l), 0)

        dp = [INF]*(len(nums)+1)
        dp[0] = 0
        for j in xrange(len(andValues)):
            new_dp = [INF]*(len(nums)+1)
            cnt = [0]*L
            l = [0]*len(dp)
            dq = collections.deque()
            left = idx = j
            for right in xrange(j, len(nums)):
                mask = update(cnt, nums[right], right-left+1, +1)
                if mask <= andValues[j]:
                    while left <= right:
                        if mask > andValues[j]:
                            break
                        mask = update(cnt, nums[left], right-left, -1)
                        left += 1
                    left -= 1
                    mask = update(cnt, nums[left], right-left+1, +1)  # try to move to the last left s.t. mask == andValues[j]
                if (andValues[j]&nums[right]) == andValues[j]:
                    l[right + 1] = l[right]+1
                if mask != andValues[j]:
                    continue
                # new_dp[right+1] = min(dp[left-l], dp[left-l+1], ..., dp[left])+nums[right]
                while idx <= left:
                    while dq and dp[dq[-1]] >= dp[idx]:
                        dq.pop()
                    dq.append(idx)
                    idx += 1
                while dq and dq[0] < left-l[left]:
                    dq.popleft()
                if dq:
                    new_dp[right+1] = dp[dq[0]]+nums[right]
            dp = new_dp
        return dp[-1] if dp[-1] != INF else -1


# Time:  O(n * m * logr), r = max(nums)
# Space: O(n * m * logr)
import collections


# memoization
class Solution2(object):
    def minimumValueSum(self, nums, andValues):
        """
        :type nums: List[int]
        :type andValues: List[int]
        :rtype: int
        """
        INF = float("inf")
        FULL_MASK = (1<<max(nums).bit_length())-1
        def memoization(i, j, mask): 
            if i == len(nums) and j == len(andValues):
                return 0
            if i == len(nums) or j == len(andValues) or mask < andValues[j]:
                return INF 
            if  mask not in lookup[i][j]:
                curr = memoization(i+1, j, mask&nums[i])
                if mask&nums[i] == andValues[j]:
                    curr = min(curr, nums[i]+memoization(i+1, j+1, FULL_MASK))
                lookup[i][j][mask] = curr
            return lookup[i][j][mask]
    
        lookup = [[collections.defaultdict(int) for _ in xrange(len(andValues))] for _ in xrange(len(nums))]
        result = memoization(0, 0, FULL_MASK)
        return result if result != INF else -1
