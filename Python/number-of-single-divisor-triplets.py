# Time:  O(d^3), d is the number of distinct nums
# Space: O(d)

import collections
import itertools

# combinatorics
class Solution(object):
    def singleDivisorTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def check(a, b, c):
            return sum((a+b+c)%x == 0 for x in (a, b, c)) == 1

        cnt = collections.Counter(nums)
        return 6*(sum(cnt[a]*cnt[b]*cnt[c] for a, b, c in itertools.combinations(cnt.keys(), 3) if check(a, b, c)) +
                  sum(cnt[a]*(cnt[a]-1)//2*cnt[b] for a, b in itertools.permutations(cnt.keys(), 2) if check(a, a, b)))
