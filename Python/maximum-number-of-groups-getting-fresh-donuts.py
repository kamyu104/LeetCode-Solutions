# Time:  O((b/2) * (n/(b/2)+1)^(b/2))
# Space: O((n/(b/2)+1)^(b/2))

# greedy + memoization solution
class Solution(object):
    def maxHappyGroups(self, batchSize, groups):
        """
        :type batchSize: int
        :type groups: List[int]
        :rtype: int
        """
        def memoization(batchSize, count, mask, remain, lookup):
            if lookup[mask] == 0:
                a_remain = 0
                if remain in count:
                    curr, basis = mask, 1
                    for i, c in count.iteritems():
                        if i == remain:
                            break
                        basis *= c+1
                        curr //= c+1
                    a_remain = curr%(count[remain]+1)
                result = 0
                if a_remain:
                    result = max(result, int(remain == 0) + memoization(batchSize, count, mask-basis, 0, lookup))
                else:
                    curr, basis = mask, 1
                    for i, c in count.iteritems():
                        if curr%(c+1):
                            result = max(result, int(remain == 0) + memoization(batchSize, count, mask-basis, (remain-i)%batchSize, lookup))
                        basis *= c+1
                        curr //= c+1
                lookup[mask] = result
            return lookup[mask]
    
        count = [0]*batchSize
        for i in groups:
            count[i%len(count)] += 1
        result = count[0]
        count[0] = 0
        for i in xrange(1, len(count)//2+1):  # optimization
            pair_count = min(count[i], count[len(count)-i]) if 2*i != len(count) else count[i]//2
            result += pair_count
            count[i] -= pair_count
            count[len(count)-i] -= pair_count
        new_count = {i:c for i, c in enumerate(count) if c}
        max_mask = reduce(lambda total, c: total*(c+1), new_count.itervalues(), 1)
        lookup = [0]*max_mask
        return result+memoization(batchSize, new_count, max_mask-1, 0, lookup)


# Time:  O((b/2) * (n/(b/2)+1)^(b/2))
# Space: O((n/(b/2)+1)^(b/2))
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
        result = count[0]
        count[0] = 0
        for i in xrange(1, len(count)//2+1):  # optimization
            pair_count = min(count[i], count[len(count)-i]) if 2*i != len(count) else count[i]//2
            result += pair_count
            count[i] -= pair_count
            count[len(count)-i] -= pair_count
        new_count = {i:c for i, c in enumerate(count) if c}
        max_mask = reduce(lambda total, c: total*(c+1), new_count.itervalues(), 1)
        dp = [0]*max_mask
        for mask in xrange(len(dp)):
            remain = 0
            curr, basis = mask, 1
            for i, c in new_count.iteritems():
                ai = curr%(c+1)
                if ai:
                    dp[mask] = max(dp[mask], dp[mask-basis])
                remain = (remain+ai*i)%batchSize
                basis *= c+1
                curr //= c+1
            if mask != len(dp)-1 and remain == 0:
                dp[mask] += 1
        return result+dp[-1]
