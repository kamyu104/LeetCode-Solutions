# Time:  O(n * 2^n), len(sums) = 2^n
# Space: O(1)

# [proof]
# - let d = sorted_sums[0]-sorted_sums[1] and d != -d (d = 0 is trival), where one of +d/-d is the smallest positive or largest negative number of the original solution of [S1, ..., S(2^n)]
# - given Sp-d = 0 for some p in [1, 2^n] and Sq-(-d) = 0 for some q in [1, 2^n]
#   assume d is a number of the original solution of [S1, ..., S(2^n)] (the proof where -d is a number of the original solution is vice versa)
#   let Sq = x1+...+xi where 1 <= i <= n-1
#   let [d]+[x1, ..., xi]+[x(i+1), ..., x(n-1)] be the original solution
#   => new_sums([S1, ..., S(2^n)], d)
#      = subset_sums([x1, ..., xi]+[x(i+1), ..., x(n-1)])
#   if we choose -d as a number of a solution of [S1, ..., S(2^n)]
#   => new_sums([S1, ..., S(2^n)], -d)
#      = new_sums([S1, ..., S(2^n)], -(x1+...+xi))
#      = subset_sums([(-x1), ..., (-xi)]+[x(i+1), ..., x(n-1)])
#      => [-d]+[(-x1), ..., (-xi)]+[x(i+1), ..., x(n-1)] is also a solution
#
# [conclusion]
# - if new_sums with +d/-d (including d = 0) both contain zero, we can choose either one
# - if only one of new_sums with +d/-d contains zero, we can only choose the one with zero since subset_sums must contain zero

# optimized from solution4 (not using dict), runtime: 1040 ms
class Solution(object):
    def recoverArray(self, n, sums):
        """
        :type n: int
        :type sums: List[int]
        :rtype: List[int]
        """
        sums.sort()  # Time: O(2^n * log(2^n)) = O(n * 2^n)
        shift, l = 0, len(sums)
        result = []
        for _ in xrange(n):  # log(2^n) times, each time costs O(2^(n-len(result))), Total Time: O(2^n)
            new_shift = sums[0]-sums[1]
            assert(new_shift <= 0)
            has_zero, j, k = False, 0, 0
            for i in xrange(l):
                if k < j and sums[k] == sums[i]:  # skip shifted one
                    k += 1
                else:
                    if shift == sums[i]-new_shift:
                        has_zero = True
                    sums[j] = sums[i]-new_shift
                    j += 1
            if has_zero:  # contain 0, choose this side
                result.append(new_shift)
            else:  # contain no 0, choose another side and shift 0 offset
                result.append(-new_shift)
                shift -= new_shift
            l //= 2
        return result


# Time:  O(2^n + n * r), len(sums) = 2^n
#                      , r = max(sums)-min(sums)
# Space: O(2^n + r)
import collections


# optimized from solution4 (not using dict), runtime: 968 ms
class Solution2(object):
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
        sorted_sums = [x for x in xrange(min_sum, max_sum+1) if dp[x-min_sum]]  # Time: O(r)
        shift = 0
        result = []
        for _ in xrange(n):  # log(2^n) times, each time costs O(2^(n-len(result)))+O(r), Total Time: O(2^n + n * r)
            new_dp = [0]*(max_sum-min_sum+1)
            new_sorted_sums = []
            new_shift = sorted_sums[0]-sorted_sums[1] if dp[sorted_sums[0]-min_sum] == 1 else 0
            assert(new_shift <= 0)
            for x in sorted_sums:
                if not dp[x-min_sum]:
                    continue
                dp[(x-new_shift)-min_sum] -= dp[x-min_sum] if new_shift else dp[x-min_sum]//2
                new_dp[(x-new_shift)-min_sum] = dp[x-min_sum]
                new_sorted_sums.append(x-new_shift)
            dp = new_dp
            sorted_sums = new_sorted_sums
            if dp[shift-min_sum]:  # contain 0, choose this side
                result.append(new_shift)
            else:  # contain no 0, choose another side and shift 0 offset
                result.append(-new_shift)
                shift -= new_shift
        return result


# Time:  O(n * 2^n), len(sums) = 2^n
# Space: O(2^n)
import collections
import operator


# optimized from solution4, runtime: 1044 ms
class Solution3(object):
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
        sorted_sums = sorted(dp.iterkeys())  # Time: O(2^n * log(2^n)) = O(n * 2^n)
        shift = 0
        result = [0]*(basis.bit_length()-1)
        for _ in xrange(n-len(result)):  # log(2^n) times, each time costs O(2^(n-len(result))), Total Time: O(2^n)
            new_dp = {}
            new_sorted_sums = []
            new_shift = sorted_sums[0]-sorted_sums[1]
            assert(new_shift < 0)
            for x in sorted_sums:
                if not dp[x]:
                    continue
                dp[x-new_shift] -= dp[x]
                new_dp[x-new_shift] = dp[x]
                new_sorted_sums.append(x-new_shift)
            dp = new_dp
            sorted_sums = new_sorted_sums
            if shift in dp:  # contain 0, choose this side
                result.append(new_shift)
            else:  # contain no 0, choose another side and shift 0 offset
                result.append(-new_shift)
                shift -= new_shift
        return result


# Time:  O(n * 2^n), len(sums) = 2^n
# Space: O(2^n)
import collections


# optimized from solution4 (not using OrderedDict), runtime: 1024 ms
class Solution4(object):
    def recoverArray(self, n, sums):
        """
        :type n: int
        :type sums: List[int]
        :rtype: List[int]
        """
        dp = {k: v for k, v in collections.Counter(sums).iteritems()}
        sorted_sums = sorted(dp.iterkeys())  # Time: O(2^n * log(2^n)) = O(n * 2^n)
        shift = 0
        result = []
        for _ in xrange(n):  # log(2^n) times, each time costs O(2^(n-len(result))), Total Time: O(2^n)
            new_dp = {}
            new_sorted_sums = []
            new_shift = sorted_sums[0]-sorted_sums[1] if dp[sorted_sums[0]] == 1 else 0
            assert(new_shift <= 0)
            for x in sorted_sums:
                if not dp[x]:
                    continue
                dp[x-new_shift] -= dp[x] if new_shift else dp[x]//2
                new_dp[x-new_shift] = dp[x]
                new_sorted_sums.append(x-new_shift)
            dp = new_dp
            sorted_sums = new_sorted_sums
            if shift in dp:  # contain 0, choose this side
                result.append(new_shift)
            else:  # contain no 0, choose another side and shift 0 offset
                result.append(-new_shift)
                shift -= new_shift
        return result


# Time:  O(n * 2^n), len(sums) = 2^n
# Space: O(2^n)
import collections


# runtime: 1720 ms
class Solution5(object):
    def recoverArray(self, n, sums):
        """
        :type n: int
        :type sums: List[int]
        :rtype: List[int]
        """
        dp = OrderedDict(sorted(collections.Counter(sums).iteritems()))  # Time: O(2^n * log(2^n)) = O(n * 2^n)
        shift = 0
        result = []
        for _ in xrange(n):  # log(2^n) times, each time costs O(2^(n-len(result))), Total Time: O(2^n)
            new_dp = OrderedDict()
            it = iter(dp)
            min_sum = next(it)
            new_shift = min_sum-next(it) if dp[min_sum] == 1 else 0
            assert(new_shift <= 0)
            for x in dp.iterkeys():
                if not dp[x]:
                    continue
                dp[x-new_shift] -= dp[x] if new_shift else dp[x]//2
                new_dp[x-new_shift] = dp[x]
            dp = new_dp
            if shift in dp:  # contain 0, choose this side
                result.append(new_shift)
            else:  # contain no 0, choose another side and shift 0 offset
                result.append(-new_shift)
                shift -= new_shift
        return result
