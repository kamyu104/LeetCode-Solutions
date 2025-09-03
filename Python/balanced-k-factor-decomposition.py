# Time:  O(k * sqrt(n)^(k - 1))
# Space: O(k)

# backtracking, number theory
class Solution(object):
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

        def backtracking(remain, start):
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
                backtracking(remain//i, i)
                curr.pop()
                    
        result, curr = [], []
        backtracking(n, 1)
        return result
