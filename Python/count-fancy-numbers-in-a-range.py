# Time:  O(dlogd + g + d^2 + g * d) = O(g * d + d^2), d = logr, g = len(good)
# Space: O(g + d)

# bfs, dp, principle of inclusion and exclusion
class Solution(object):
    def countFancy(self, l, r):
        """
        :type l: int
        :type r: int
        :rtype: int
        """
        def count(x):
            def length(n):  # Time: O(logn)
                result = 0
                while n:
                    result += 1
                    n //= 10
                return result

            def total(n):  # Time: O(logn)
                result = 0
                while n:
                    result += i%10
                    n //= 10
                return result

            def check(n):  # Time: O(logn)
                asc = desc = True
                while n >= 10:
                    if not (n//10)%10 < n%10:
                        asc = False
                    if not (n//10)%10 > n%10:
                        desc = False
                    n //= 10
                return asc or desc

            def bfs(x):  # Time: O(g), g = len(result)
                result = [i for i in xrange(1, min(9, x)+1)]
                for diff in (1, -1):
                    q = []
                    for i in xrange(1, min(9, x)+1):
                        q.append(i)
                    while q:
                        new_q = []
                        for u in q:
                            curr = u%10
                            d = curr+diff
                            while 0 <= d <= 9:
                                v = u*10+d
                                if v <= x:
                                    new_q.append(v)
                                    result.append(v)
                                d += diff
                        q = new_q
                return result

            def dp(x):  # Time: O(d^2), d = logr
                l = length(x)
                mx = l*9
                dp = [[0]*(mx+1) for _ in xrange(2)]  # dp[tight][sum]
                dp[1][0] = 1
                base = 10**(l-1)
                for i in xrange(l):
                    new_dp = [[0]*(mx+1) for _ in xrange(2)]
                    v = (x//base)%10
                    base //= 10
                    for t in xrange(2):
                        for s in xrange(mx+1):
                            if dp[t][s] == 0:
                                continue
                            for d in xrange((v if t == 1 else 9)+1):
                                new_dp[t == 1 and d == v][s+d] += dp[t][s]
                    dp = new_dp
                return sum(dp[0][i]+dp[1][i] for i in xrange(mx+1) if lookup[i])

            lookup = [check(i) for i in xrange(length(x)*9+1)]
            good = bfs(x)
            return len(good)+dp(x)-sum(lookup[total(x)] for x in good)

        return count(r)-count(l-1)
