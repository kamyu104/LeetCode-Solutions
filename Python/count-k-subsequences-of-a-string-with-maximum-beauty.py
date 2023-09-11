# Time:  O(n)
# Space: O(1)

import collections
import random


# greedy, quick select, combinatorics
class Solution(object):
    def countKSubsequencesWithMaxBeauty(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        fact, inv, inv_fact = [[1]*2 for _ in xrange(3)]
        def nCr(n, k):
            if not (0 <= k <= n):
                return 0
            while len(inv) <= n:  # lazy initialization
                fact.append(fact[-1]*len(inv) % MOD)
                inv.append(inv[MOD%len(inv)]*(MOD-MOD//len(inv)) % MOD)  # https://cp-algorithms.com/algebra/module-inverse.html
                inv_fact.append(inv_fact[-1]*inv[-1] % MOD)
            return (fact[n]*inv_fact[n-k] % MOD) * inv_fact[k] % MOD

        def nth_element(nums, n, compare=lambda a, b: a < b):
            def tri_partition(nums, left, right, target, compare):
                mid = left
                while mid <= right:
                    if nums[mid] == target:
                        mid += 1
                    elif compare(nums[mid], target):
                        nums[left], nums[mid] = nums[mid], nums[left]
                        left += 1
                        mid += 1
                    else:
                        nums[mid], nums[right] = nums[right], nums[mid]
                        right -= 1
                return left, right

            left, right = 0, len(nums)-1
            while left <= right:
                pivot_idx = random.randint(left, right)
                pivot_left, pivot_right = tri_partition(nums, left, right, nums[pivot_idx], compare)
                if pivot_left <= n <= pivot_right:
                    return
                elif pivot_left > n:
                    right = pivot_left-1
                else:  # pivot_right < n.
                    left = pivot_right+1

        cnt = collections.Counter(s)
        if len(cnt) < k:
            return 0
        freqs = cnt.values()
        nth_element(freqs, k-1, lambda a, b: a > b)
        n = freqs.count(freqs[k-1])
        r = sum(freqs[i] == freqs[k-1] for i in xrange(k))
        return reduce(lambda a, b: a*b%MOD, (freqs[i] for i in xrange(k)), 1)*nCr(n, r)%MOD
