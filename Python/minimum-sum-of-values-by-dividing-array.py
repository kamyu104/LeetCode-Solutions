# Time:  O(n * m * logr), r = max(nums)
# Space: O(n + logr)

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
        def update(cnt, x, d):
            for i in xrange(L):
                if x&(1<<i):
                    cnt[i] += d
        
        def mask(cnt, l):
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
                update(cnt, nums[right], +1)
                if mask(cnt, right-left+1) <= andValues[j]:
                    while left <= right:
                        if mask(cnt, right-left+1) > andValues[j]:
                            break
                        update(cnt, nums[left], -1)
                        left += 1
                    left -= 1
                    update(cnt, nums[left], +1)  # try to move to the last left s.t. mask(cnt, right-left+1) == andValues[j]
                if (andValues[j]&nums[right]) == andValues[j]:
                    l[right + 1] = l[right]+1
                if mask(cnt, right-left+1) != andValues[j]:
                    continue
                # new_dp[right+1] = min(dp[left-l[left]], dp[left-l[left]+1], ..., dp[left])+nums[right]
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


# Time:  O(n * m * (logn + logr)), r = max(nums)
# Space: O(n + logr)
# dp, sparse table
class Solution2(object):
    def minimumValueSum(self, nums, andValues):
        """
        :type nums: List[int]
        :type andValues: List[int]
        :rtype: int
        """
        INF = float("inf")
        # RMQ - Sparse Table
        # Template: https://github.com/kamyu104/GoogleCodeJam-Farewell-Rounds/blob/main/Round%20D/genetic_sequences2.py3
        # Time:  ctor:  O(NlogN) * O(fn)
        #        query: O(fn)
        # Space: O(NlogN)
        class SparseTable(object):
            def __init__(self, arr, fn):
                self.fn = fn
                self.bit_length = [0]
                n = len(arr)
                k = n.bit_length()-1  # log2_floor(n)
                for i in xrange(k+1):
                    self.bit_length.extend(i+1 for _ in xrange(min(1<<i, (n+1)-len(self.bit_length))))
                self.st = [[0]*n for _ in xrange(k+1)]
                self.st[0] = arr[:]
                for i in xrange(1, k+1):  # Time: O(NlogN) * O(fn)
                    for j in xrange((n-(1<<i))+1):
                        self.st[i][j] = fn(self.st[i-1][j], self.st[i-1][j+(1<<(i-1))])
        
            def query(self, L, R):  # Time: O(fn)
                i = self.bit_length[R-L+1]-1  # log2_floor(R-L+1)
                return self.fn(self.st[i][L], self.st[i][R-(1<<i)+1])
        
        dp = [INF]*(len(nums)+1)
        dp[0] = 0
        for j in xrange(len(andValues)):
            new_dp = [INF]*(len(nums)+1)
            masks = []
            st = SparseTable(dp, min)
            for i in xrange(j, len(nums)):
                masks.append([nums[i], i])
                for x in masks:
                    x[0] &= nums[i]
                masks = [x for k, x in enumerate(masks) if k == 0 or masks[k-1][0] != masks[k][0]]
                for k, [mask, left] in enumerate(masks):
                    if mask == andValues[j]:
                        # any j in range(left, right+1) has same and(nums[j:i+1]) = mask
                        right = masks[k+1][1]-1 if k+1 != len(masks) else i
                        new_dp[i+1] = min(new_dp[i+1], st.query(left, right)+nums[i])
                        break
            dp = new_dp
        return dp[-1] if dp[-1] != INF else -1


# Time:  O(n * m * logr), r = max(nums)
# Space: O(n * m * logr)
import collections


# memoization
class Solution3(object):
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
