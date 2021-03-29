# Time:  O(sqrt(n))
# Space: O(sqrt(n))

class Solution(object):
    def reinitializePermutation(self, n):
        """
        :type n: int
        :rtype: int
        """
        # reference: https://cp-algorithms.com/algebra/discrete-log.html
        def discrete_log(a, b, m):
            a %= m
            b %= m
            n = int(m**0.5)+1
            an = pow(a, n, m)
            vals = {}
            curr = b
            for q in xrange(n+1):
                vals[curr] = q
                curr = curr*a % m
            curr = 1
            for p in xrange(1, n+1):
                curr = curr*an % m
                if curr in vals:
                    return n*p-vals[curr]
            return -1

        return 1+discrete_log(2, n//2, n-1)  # find min x s.t. 2^x mod (n-1) = n/2, result is x + 1


# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def reinitializePermutation(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 2:
            return 1
        result, i = 0, 1
        while not result or i != 1:
            i = (i*2)%(n-1)
            result += 1
        return result


# Time:  O(n)
# Space: O(1)
class Solution3(object):
    def reinitializePermutation(self, n):
        """
        :type n: int
        :rtype: int
        """
        result, i = 0, 1
        while not result or i != 1:  # find cycle length
            i = (i//2 if not i%2 else n//2+(i-1)//2)
            result += 1
        return result
