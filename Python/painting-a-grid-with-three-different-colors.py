# Time:  O(4^m + n * 3^m)
# Space: O(3^m)

import collections


# worse complexity, but faster due to too small m
class Solution(object):
    def colorTheGrid(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        def backtracking(mask, b, result):  # Time: O(2^m), Space: O(2^m)
            if b == 0:
                result.append(mask)
                return
            for i in xrange(3):
                if mask == -1 or mask//(b*3)%3 != i:
                    backtracking(mask+i*b if mask != -1 else i*b, b//3, result)
    
        def backtracking2(mask1, mask2, b, result):  # Time: O(2^m), Space: O(3^m)
            if b == 0:
                result.append(mask2)
                return
            for i in xrange(3):
                if mask1//b%3 != i and (mask2 == -1 or mask2//(b*3)%3 != i):
                    backtracking2(mask1, mask2+i*b if mask2 != -1 else i*b, b//3, result)
 
        if m > n:
            m, n = n, m
        basis = 3**(m-1)
        masks = []
        backtracking(-1, basis, masks)  # Time:  O(2^m), Space: O(2^m)
        adj = collections.defaultdict(list)
        for mask in masks:  # Time: O(4^m), Space: O(3^m)
            backtracking2(mask, -1, basis, adj[mask])
        assert(sum(len(v) for v in adj.itervalues()) <= 2*3**m)
        dp = collections.Counter(masks)
        for _ in xrange(n-1):  # Time: O(n*3^m), Space: O(2^m)
            assert(len(dp) <= 3*3*2**(m-2))
            new_dp = collections.Counter()
            for mask, v in dp.iteritems():
                for new_mask in adj[mask]:
                    new_dp[new_mask] = (new_dp[new_mask] + v) % MOD
            dp = new_dp
        return reduce(lambda x,y: (x+y)%MOD, dp.itervalues(), 0)  # Time: O(2^m)


# Time:  (m * n grids) * (O(3*3*2^(m-2)) possible states per grid) = O(n * m * 2^m)
# Space: O(3*3*2^(m-2)) = O(2^m)
import collections


# better complexity, but slower due to too small m
class Solution2(object):
    def colorTheGrid(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        if m > n:
            m, n = n, m
        basis = 3**(m-1)
        dp = collections.Counter({3**m-1: 1})
        for idx in xrange(m*n):
            assert(len(dp) <= 3**2 * 2**(m-2))
            r, c = divmod(idx, m)
            new_dp = collections.Counter()
            for mask, v in dp.iteritems():
                choices = {0, 1, 2}
                if r > 0:
                    choices.discard(mask%3)  # get up grid
                if c > 0:
                    choices.discard(mask//basis)  # get left grid
                for x in choices:
                    new_mask = (x*basis)+(mask//3)  # encoding mask
                    new_dp[new_mask] = (new_dp[new_mask]+v)%MOD 
            dp = new_dp
        return reduce(lambda x,y: (x+y)%MOD, dp.itervalues(), 0)  # Time: O(2^m)
