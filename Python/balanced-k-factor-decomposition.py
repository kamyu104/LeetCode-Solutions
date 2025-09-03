# Time:  precompute: O(rlogr)
#        runtime:    O(k * (logn)^(k - 1))
# Space: O(rlogr)

import bisect


# backtracking, number theory
def factors(n):
    result = [[] for _ in xrange(n+1)]
    for i in xrange(1, n+1):
        for j in range(i, n+1, i):
            result[j].append(i)
    return result


MAX_N = 10**5
FACTORS = factors(MAX_N)
class Solution(object):
    def minDifference(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        def backtracking(remain):
            start = curr[-1] if curr else 1
            if len(curr) == k-1 and remain >= start:
                curr.append(remain)
                if not result or result[-1]-result[0] > curr[-1]-curr[0]:
                    result[:] = curr
                curr.pop()
                return
            factors = FACTORS[remain]
            for i in xrange(bisect.bisect_left(factors, start), len(factors)):
                curr.append(factors[i])
                backtracking(remain//factors[i])
                curr.pop()
                    
        result, curr = [], []
        backtracking(n)
        return result    


# Time:  O(k * (n^(1/2) * n^(1/4) * n^(1/8) * n^(1/6) + n^(1/2) * n^(1/4) * n^(1/8) + n^(1/2) * n^(1/4) + n^(1/2))) <= O(k^2 * n)
# Space: O(k)
# backtracking, number theory
class Solution2(object):
    def minDifference(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        def factors(n):
            for i in xrange(1, n+1):
                if i*i > n:
                    break
                if n%i:
                    continue
                yield i
                if n//i != i:
                    yield n//i

        def backtracking(remain):
            start = curr[-1] if curr else 1
            if len(curr) == k-1 and remain >= start:
                curr.append(remain)
                if not result or result[-1]-result[0] > curr[-1]-curr[0]:
                    result[:] = curr
                curr.pop()
                return
            for i in factors(remain):
                if i < start:
                    continue
                curr.append(i)
                backtracking(remain//i)
                curr.pop()
                    
        result, curr = [], []
        backtracking(n)
        return result


# Time:  O(2^(k-1) * k * n)
# Space: O(k)
# backtracking, number theory
class Solution3(object):
    def minDifference(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        def factors(n):
            for i in xrange(1, n+1):
                if i*i > n:
                    break
                if n%i:
                    continue
                yield i
                if n//i != i:
                    yield n//i

        def backtracking(remain):
            if len(curr) == k-1:
                curr.append(remain)
                if not result or max(result)-min(result) > max(curr)-min(curr):
                    result[:] = curr
                curr.pop()
                return
            for i in factors(remain):
                curr.append(i)
                backtracking(remain//i)
                curr.pop()
                    
        result, curr = [], []
        backtracking(n)
        return result
