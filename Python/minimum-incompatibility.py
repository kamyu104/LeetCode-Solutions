# Time:  O(nlogn + k * n)
# Space: O(n)

import collections


class Solution(object):
    def minimumIncompatibility(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def greedy(nums, k, is_reversed):
            count = collections.Counter(nums)
            if max(count.itervalues()) > k:
                return -1
            sorted_keys = sorted(count.keys(), reverse=is_reversed)
            stks = [[] for _ in xrange(k)] 
            remain = len(nums)
            for x in sorted_keys:
                if count[x] != len(stks):
                    continue
                for i in xrange(len(stks)):
                    stks[i].append(x)
                remain -= count[x]
                count[x] = 0
            curr = 0
            while remain:
                for i, x in enumerate(sorted_keys):
                    if not count[x]:
                        continue
                    stks[curr].append(x)
                    remain -= 1
                    count[x] -= 1
                    if len(stks[curr]) == len(nums)//k:  # total time = O(k * n)
                        curr += 1
                        for x in sorted_keys:
                            if count[x] != len(stks)-curr:
                                continue
                            for i in xrange(curr, len(stks)):
                                stks[i].append(x)
                            remain -= count[x]
                            count[x] = 0
                        break
            return sum([max(stk)-min(stk) for stk in stks])

        return min(greedy(nums, k, False), greedy(nums, k, True)) 


# Time:  O(sum(i*d * nCr(i*d, d) * nCr(n, i*d) for i in xrange(1, k+1))) < O(sum(n * 2^m * nCr(n, m) for m in xrange(n+1))) = O(n * 3^n)
# Space: O(n * k)
import itertools


class Solution2(object):
    def minimumIncompatibility(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        inf = (len(nums)-1)*(len(nums)//k)+1
        def backtracking(nums, d, lookup):
            if not nums:
                return 0
            if nums not in lookup:
                ret = inf
                for new_nums in itertools.combinations(nums, d):
                    new_nums_set = set(new_nums)
                    if len(new_nums_set) < d:
                        continue
                    left = []
                    for num in nums:
                        if num in new_nums_set:
                            new_nums_set.remove(num)
                            continue
                        left.append(num)
                    ret = min(ret, max(new_nums)-min(new_nums) + backtracking(tuple(left), d, lookup))
                lookup[nums] = ret
            return lookup[nums]
        
        result = backtracking(tuple(nums), len(nums)//k, {})
        return result if result != inf else -1


# Time:  O(max(n * 2^n, 3^n))
# Space: O(2^n)
class Solution_TLE(object):
    def minimumIncompatibility(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        inf = (len(nums)-1)*(len(nums)//k)+1
        POW = [1]
        for i in xrange(len(nums)):
            POW.append(POW[-1]<<1)
        
        def popcount(n):
            result = 0
            while n:
                n &= n - 1
                result += 1
            return result
    
        def find_candidates(nums, k):
            total = POW[len(nums)]-1
            m = len(nums)//k
            result = [inf]*(total+1)
            for mask in xrange(total+1):
                if popcount(mask) != m:
                    continue
                lookup = 0
                mx, mn = 0, inf
                for i in xrange(len(nums)):
                    if mask&POW[i] == 0:
                        continue
                    if lookup&POW[nums[i]]:
                        break
                    lookup |= POW[nums[i]]
                    mx = max(mx, nums[i])
                    mn = min(mn, nums[i])
                else:
                    result[mask] = mx-mn
            return result
        
        candidates = find_candidates(nums, k)
        m = len(nums)//k
        total = POW[len(nums)]-1
        dp = [inf]*(total+1)
        dp[0] = 0
        for mask in xrange(total+1):
            if popcount(mask) % m != 0:
                continue
            # submask enumeration:
            # => sum(nCr(n, k) * 2^k for k in xrange(n+1)) = (1 + 2)^n = 3^n
            # => Time: O(3^n), see https://cp-algorithms.com/algebra/all-submasks.html
            submask = mask
            while submask:
                dp[mask] = min(dp[mask], dp[mask-submask] + candidates[submask])
                submask = (submask-1)&mask
        return dp[-1] if dp[-1] != inf else -1
