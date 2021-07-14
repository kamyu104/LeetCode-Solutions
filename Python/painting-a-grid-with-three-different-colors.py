# Time:  O((m + n) * 3^m) = O(n * 3^m) since m <= n
# Space: O(3^m)

import collections


# better complexity for small m, large n
class Solution(object):
    def colorTheGrid(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        def backtracking(mask1, mask2, basis, result):  # Time: O(2^m), Space: O(2^m)
            if not basis:
                result.append(mask2)
                return
            for i in xrange(3):
                if (mask1 == -1 or mask1//basis%3 != i) and (mask2 == -1 or mask2//(basis*3)%3 != i):
                    backtracking(mask1, mask2+i*basis if mask2 != -1 else i*basis, basis//3, result)
 
        def normalize(m, mask):
            norm = {}
            result, basis = 0, 1
            while m:
                x = mask//basis%3
                if x not in norm:
                    norm[x] = len(norm)
                result += norm[x]*basis
                basis *= 3
                m -= 1
            return result
    
        if m > n:
            m, n = n, m
        basis = 3**(m-1)
        masks = []
        backtracking(-1, -1, basis, masks)  # Time: O(2^m), Space: O(2^m)
        assert(len(masks) == 3 * 2**(m-1))
        adj = collections.defaultdict(list)
        for mask in masks:  # O(3^m) leaves in depth O(m) => Time: O(m * 3^m), Space: O(3^m)
            backtracking(mask, -1, basis, adj[mask])
        # proof:
        #   'o' uses the same color with its bottom-left one, 
        #   'x' uses the remaining color different from its left one and bottom-left one,
        #   k is the cnt of 'o', 
        #     [3, 1(o), 1(x), 1(o), ..., 1(o), 1(x)] => nCr(m-1, k) * 3 * 2 * 2^k for k in xrange(m) = 3 * 2 * (2+1)^(m-1) = 2*3^m combinations
        #     [2,    2,    1,    2, ...,  2,      1]
        # another proof:
        #   given previous pair of colors, each pair of '?' has 3 choices of colors
        #     [3, ?, ?, ..., ?] => 3 * 2 * 3^(m-1) = 2*3^m combinations
        #         |  |       |
        #         3  3       3
        #         |  |       |
        #     [2, ?, ?, ..., ?]
        assert(sum(len(v) for v in adj.itervalues()) == 2*3**m)
        lookup = {mask:normalize(m, mask) for mask in masks}  # Time: O(m * 2^m)
        dp = collections.Counter(lookup[mask] for mask in masks)  # normalize colors to speed up performance
        for _ in xrange(n-1):  # Time: O(n * 3^m), Space: O(2^m)
            assert(len(dp) == 3*2**(m-1)// 3 // (2 if m >= 2 else 1))  # divided by 3 * 2 is since the first two colors are normalized to speed up performance
            new_dp = collections.Counter()
            for mask, v in dp.iteritems():
                for new_mask in adj[mask]:
                    new_dp[lookup[new_mask]] = (new_dp[lookup[new_mask]] + v) % MOD
            dp = new_dp
        return reduce(lambda x,y: (x+y)%MOD, dp.itervalues(), 0)  # Time: O(2^m)


# Time:  O(m * 3^m + 2^(3 * m) * logn)
# Space: O(2^(2 * m))
import collections
import itertools


# better complexity for small m, super large n
# matrix exponentiation solution
class Solution2(object):
    def colorTheGrid(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        def find_masks(m, basis):  # Time: 3 + 3*2 + 3*2*2 + ... + 3*2^(m-1) = 3 * (2^m - 1) = O(2^m), Space: O(2^m)
            masks = set([0])
            for c in xrange(m):
                new_masks = set()
                for mask in masks:
                    choices = {0, 1, 2}
                    if c > 0:
                        choices.discard(mask//basis)  # get left grid
                    for x in choices:
                        new_masks.add((x*basis)+(mask//3))  # encoding mask
                masks = new_masks
            return masks

        def find_adj(m, basis, masks):  # Time: O(m * 3^m), Space: O(3^m)
            adj = collections.defaultdict(set)
            for mask in masks:  # O(2^m)
                adj[mask].add(mask)
            for c in xrange(m):
                new_adj = collections.defaultdict(set)
                for mask1, mask2s in adj.iteritems():
                    for mask in mask2s:
                        choices = {0, 1, 2}
                        choices.discard(mask%3)  # get up grid
                        if c > 0:
                            choices.discard(mask//basis)  # get left grid
                        for x in choices:
                            new_adj[mask1].add((x*basis)+(mask//3))  # encoding mask
                adj = new_adj
            return adj

        def matrix_mult(A, B):
            ZB = zip(*B)
            return [[sum(a*b % MOD for a, b in itertools.izip(row, col)) % MOD for col in ZB] for row in A]
 
        def matrix_expo(A, K):
            result = [[int(i == j) for j in xrange(len(A))] for i in xrange(len(A))]
            while K:
                if K % 2:
                    result = matrix_mult(result, A)
                A = matrix_mult(A, A)
                K /= 2
            return result

        if m > n:
            m, n = n, m
        basis = 3**(m-1)
        masks = set()
        masks = find_masks(m, basis)  # alternative of backtracking, Time: O(2^m), Space: O(2^m)
        assert(len(masks) == 3 * 2**(m-1))
        adj = find_adj(m, basis, masks)  # alternative of backtracking, Time: O(m * 3^m), Space: O(3^m)
        assert(sum(len(v) for v in adj.itervalues()) == 2*3**m)
        return reduce(lambda x,y: (x+y)%MOD,
                      matrix_mult([[1]*len(masks)],
                      matrix_expo([[int(mask2 in adj[mask1]) for mask2 in masks] for mask1 in masks], n-1))[0],
                      0)  # Time: O((2^m)^3 * logn), Space: O((2^m)^2)


# Time:  (m * n grids) * (O(3*3*2^(m-2)) possible states per grid) = O(n * m * 2^m)
# Space: O(3*3*2^(m-2)) = O(2^m)
import collections


# better complexity for large m, large n
class Solution3(object):
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
        dp = collections.Counter({0: 1})
        for idx in xrange(m*n):
            r, c = divmod(idx, m)
            # sliding window with size m doesn't cross rows:
            #   [3, 2, ..., 2] => 3*2^(m-1) combinations
            assert(r != 0 or c != 0 or len(dp) == 1)
            assert(r != 0 or c == 0 or len(dp) == 3*2**(c-1))
            assert(r == 0 or c != 0 or len(dp) == 3*2**(m-1))
            # sliding window with size m crosses rows:
            #   [*, ..., *, *, 3, 2, ..., 2] => 3*3 * 2^(m-2) combinations
            #   [2, ..., 2, 3, *, *, ..., *]
            assert(r == 0 or c == 0 or len(dp) == 3**2 * 2**(m-2))
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
