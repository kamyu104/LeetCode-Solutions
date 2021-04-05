# Time:  O(b * (n/b+1)^b)
# Space: O((n/b+1)^b)

# greedy + memoization solution
class Solution(object):
    def maxHappyGroups(self, batchSize, groups):
        """
        :type batchSize: int
        :type groups: List[int]
        :rtype: int
        """
        def memoization(count, mask, remain, lookup):
            if lookup[mask] == 0:
                curr, basis = mask, 1
                for i in xrange(remain):
                    basis *= count[i]+1
                    curr //= count[i]+1
                a_remain = curr%(count[remain]+1)
                result = 0
                if a_remain:
                    result = max(result, int(remain == 0) + memoization(count, mask-basis, 0, lookup))
                else:
                    curr, basis = mask, 1
                    for i, c in enumerate(count):
                        if curr%(c+1):
                            result = max(result, int(remain == 0) + memoization(count, mask-basis, (remain-i)%len(count), lookup))
                        basis *= c+1
                        curr //= c+1
                lookup[mask] = result
            return lookup[mask]
    
        count = [0]*batchSize
        for i in groups:
            count[i%len(count)] += 1
        max_mask = reduce(lambda total, c: total*(c+1), count, 1)
        lookup = [0]*max_mask
        return memoization(count, max_mask-1, 0, lookup)


# Time:  O(b * (n/b+1)^b)
# Space: O((n/b+1)^b)
# dp solution
class Solution2(object):
    def maxHappyGroups(self, batchSize, groups):
        """
        :type batchSize: int
        :type groups: List[int]
        :rtype: int
        """
        count = [0]*batchSize
        for i in groups:
            count[i%len(count)] += 1
        max_mask = reduce(lambda total, c: total*(c+1), count, 1)
        dp = [0]*max_mask
        for mask in xrange(len(dp)):
            remain = 0
            curr, basis = mask, 1
            for i, c in enumerate(count):
                ai = curr%(c+1)
                if ai:
                    dp[mask] = max(dp[mask], dp[mask-basis])
                remain = (remain+ai*i)%len(count)
                basis *= c+1
                curr //= c+1
            if mask != len(dp)-1 and remain == 0:
                dp[mask] += 1
        return dp[-1]
