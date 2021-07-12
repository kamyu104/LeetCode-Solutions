# Time:  O(4^m + (m + n) * 3^m)
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
        MOD = 10**9 + 7
        def backtracking(prev, m, result):  # Time: O(2^m), Space: O(2^m)
            if not m:
                result.append(prev)
                return
            for i in xrange(3):
                if prev != -1 and prev%3 == i:
                    continue
                backtracking(prev*3+i if prev != -1 else i, m-1, result)
    
        def check(m, mask1, mask2): # Time: O(m)
            while m:
                mask1, x = divmod(mask1, 3)
                mask2, y = divmod(mask2, 3)
                if x == y:
                    return False
                m -= 1
            return True

        if m > n:
            m, n = n, m
        masks = []
        backtracking(-1, m, masks)  # Time:  O(2^m), Space: O(2^m)
        adj = collections.defaultdict(list)
        for mask1 in masks:  # Time: O(4^m + m*3^m), Space: O(3^m)
            for mask2 in masks:
                if check(m, mask1, mask2):
                    adj[mask1].append(mask2)
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
        dp = collections.Counter({3**m-1: 1})
        basis = 3**(m-1)
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
