# Time:  O(n * 2^n), len(sums) = 2^n
# Space: O(2^n)

import collections
import operator


# optimized from solution2
class Solution(object):
    def recoverArray(self, n, sums):
        """
        :type n: int
        :type sums: List[int]
        :rtype: List[int]
        """
        dp = {k: v for k, v in collections.Counter(sums).iteritems()}
        total = reduce(operator.ior, dp.itervalues(), 0)
        basis = total&-total  # find rightmost bit 1
        if basis > 1:
            for k in dp.iterkeys():
                dp[k] //= basis
        sorted_nums = sorted(dp.iterkeys())  # Time: O(2^n * log(2^n)) = O(n * 2^n)
        shift = 0
        result = [0]*(basis.bit_length()-1)
        while len(result) != n:  # log(2^n) times, each time costs O(2^(n-len(result))), Total Time: O(2^n)
            new_dp = {}
            new_sorted_nums = []
            new_shift = sorted_nums[0]-sorted_nums[1]
            assert(new_shift < 0)
            for x in sorted_nums:
                if not dp[x]:
                    continue
                dp[x-new_shift] -= dp[x]
                new_dp[x-new_shift] = dp[x]
                new_sorted_nums.append(x-new_shift)
            dp = new_dp
            sorted_nums = new_sorted_nums
            if shift in dp:
                result.append(new_shift)
            else:
                result.append(-new_shift)
                shift -= new_shift
        return result


# Time:  O(n * 2^n), len(sums) = 2^n
# Space: O(2^n)
import collections


class Solution2(object):
    def recoverArray(self, n, sums):
        """
        :type n: int
        :type sums: List[int]
        :rtype: List[int]
        """
        dp = {k: v for k, v in collections.Counter(sums).iteritems()}
        sorted_nums = sorted(dp.iterkeys())  # Time: O(2^n * log(2^n)) = O(n * 2^n)
        shift = 0
        result = []
        while len(result) != n:  # log(2^n) times, each time costs O(2^(n-len(result))), Total Time: O(2^n)
            new_dp = {}
            new_sorted_nums = []
            new_shift = sorted_nums[0]-sorted_nums[1] if dp[sorted_nums[0]] == 1 else 0
            assert(new_shift <= 0)
            for x in sorted_nums:
                if not dp[x]:
                    continue
                dp[x-new_shift] -= dp[x] if new_shift else dp[x]//2
                new_dp[x-new_shift] = dp[x]
                new_sorted_nums.append(x-new_shift)
            dp = new_dp
            sorted_nums = new_sorted_nums
            if shift in dp:
                result.append(new_shift)
            else:
                result.append(-new_shift)
                shift -= new_shift
        return result



# Time:  O(n * (2^n + r)), len(sums) = 2^n
#                        , r = max(sums)-min(sums)
# Space: O(2^n + r)
import collections


# optimized from solution2 (not using dict)
class Solution3(object):
    def recoverArray(self, n, sums):
        """
        :type n: int
        :type sums: List[int]
        :rtype: List[int]
        """
        min_sum, max_sum = min(sums), max(sums)
        dp = [0]*(max_sum-min_sum+1)
        for x in sums:
            dp[x-min_sum] += 1
        sorted_nums = [x for x in xrange(min_sum, max_sum+1) if dp[x-min_sum]]  # Time: O(r)
        shift = 0
        result = []
        while len(result) != n:  # log(2^n) times, each time costs O(2^(n-len(result)))+O(r), Total Time: O(2^n + n * r)
            new_dp = [0]*(max_sum-min_sum+1)
            new_sorted_nums = []
            new_shift = sorted_nums[0]-sorted_nums[1] if dp[sorted_nums[0]-min_sum] == 1 else 0
            assert(new_shift <= 0)
            for x in sorted_nums:
                if not dp[x-min_sum]:
                    continue
                dp[(x-new_shift)-min_sum] -= dp[x-min_sum] if new_shift else dp[x-min_sum]//2
                new_dp[(x-new_shift)-min_sum] = dp[x-min_sum]
                new_sorted_nums.append(x-new_shift)
            dp = new_dp
            sorted_nums = new_sorted_nums
            if dp[shift-min_sum]:
                result.append(new_shift)
            else:
                result.append(-new_shift)
                shift -= new_shift
        return result
