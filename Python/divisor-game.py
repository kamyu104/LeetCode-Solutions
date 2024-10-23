# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def divisorGame(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # 1. if we get an even, we can choose x = 1
        #    to make the opponent always get an odd
        # 2. if the opponent gets an odd, he can only choose x = 1 or other odds
        #    and we can still get an even
        # 3. at the end, the opponent can only choose x = 1 and we win
        # 4. in summary, we win if only if we get an even and 
        #    keeps even until the opponent loses
        return n % 2 == 0


# Time:  O(nlogn)
# Space: O(nlogn)
# dp, number theory
class Solution2(object):
    def divisorGame(self, n):
        """
        :type n: int
        :rtype: bool
        """
        def factors(n):
            result = [[] for _ in xrange(n+1)]
            for i in xrange(1, n+1):
                for j in range(i, n+1, i):
                    result[j].append(i)
            return result

        FACTORS = factors(n)
        dp = [False]*(n+1)
        for i in xrange(2, n+1):
            dp[i] = any(not dp[i-j] for j in FACTORS[i] if j != i)
        return dp[-1]


# Time:  O(nlogn)
# Space: O(nlogn)
# memoization, number theory
class Solution3(object):
    def divisorGame(self, n):
        """
        :type n: int
        :rtype: bool
        """
        def factors(n):
            result = [[] for _ in xrange(n+1)]
            for i in xrange(1, n+1):
                for j in range(i, n+1, i):
                    result[j].append(i)
            return result
    
        def memoization(n):
            if lookup[n] is None:
                lookup[n] = any(not memoization(n-i) for i in FACTORS[n] if i != n)
            return lookup[n]

        FACTORS = factors(n)
        lookup = [None]*(n+1)
        return memoization(n)


# Time:  O(n^(3/2))
# Space: O(n)
# memoization
class Solution4(object):
    def divisorGame(self, n):
        """
        :type n: int
        :rtype: bool
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
    
        def memoization(n):
            if lookup[n] is None:
                lookup[n] = any(not memoization(n-i) for i in factors(n) if i != n)
            return lookup[n]

        lookup = [None]*(n+1)
        return memoization(n)


# Time:  O(n^2)
# Space: O(n)
# memoization
class Solution5(object):
    def divisorGame(self, n):
        """
        :type n: int
        :rtype: bool
        """
        def factors(n):
            for i in xrange(1, n+1):
                if n%i:
                    continue
                yield i
    
        def memoization(n):
            if lookup[n] is None:
                lookup[n] = any(not memoization(n-i) for i in factors(n) if i != n)
            return lookup[n]

        lookup = [None]*(n+1)
        return memoization(n)
