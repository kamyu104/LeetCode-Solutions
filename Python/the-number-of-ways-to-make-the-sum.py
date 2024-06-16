# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def numberOfWays(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
  
        # n = 1
        # 1

        # n = 2
        # extend:
        # 1 1
        # new:
        # 2 (extra)

        # n = 3
        # extend:
        # 1 1 1
        # 1 2

        # n = 4
        # extend:
        # 1 1 1 1
        # 1 1 2
        # new:
        # 2 2
        # 4 (extra)

        # n = 5
        # extend
        # 1 1 1 1 1
        # 1 1 1 2
        # 1 2 2
        # 1 4

        # n = 6
        # extend:
        # 1 1 1 1 1 1
        # 1 1 1 1 2
        # 1 1 2 2
        # 1 1 4
        # new:
        # 2 2 2
        # 6 (extra)
        # 2 4

        # n = 7
        # extend
        # 1 1 1 1 1 1 1
        # 1 1 1 1 1 2
        # 1 1 1 2 2
        # 1 1 1 4
        # 1 2 2 2
        # 1 6
        # 1 2 4

        # n = 8
        # extend:
        # 1 1 1 1 1 1 1 1
        # 1 1 1 1 1 1 2
        # 1 1 1 1 2 2
        # 1 1 1 1 4
        # 1 1 2 2 2
        # 1 1 6
        # 1 1 2 4
        # new:
        # 2 2 2 2
        # 2 6 (1x2, 0x4)
        # 2 2 4 (2x2, 1x4)
        # 4 4 (extra, 0x2, 2x4)

        # n = 9
        # extend:
        # 1 1 1 1 1 1 1 1 1
        # 1 1 1 1 1 1 1 2
        # 1 1 1 1 1 2 2
        # 1 1 1 1 1 4
        # 1 1 1 2 2 2
        # 1 1 1 6
        # 1 1 1 2 4
        # 1 2 2 2 2
        # 1 2 6 (1x2, 0x4)
        # 1 2 2 4 (2x2, 1x4)
        # 1 4 4 (0x2, 2x4)

        # n = 10
        # extend:
        # 1 1 1 1 1 1 1 1 1 1
        # 1 1 1 1 1 1 1 1 2
        # 1 1 1 1 1 1 2 2
        # 1 1 1 1 1 1 4
        # 1 1 1 1 2 2 2
        # 1 1 1 1 6
        # 1 1 1 1 2 4
        # 1 1 2 2 2 2
        # 1 1 2 6 
        # 1 1 2 2 4
        # 1 1 4 4
        # new:
        # 2 2 2 2 2
        # 2 2 2 4 
        # 2 2 6 (2x2, 0x4)
        # 6 4 (extra, 0x2, 1x4)
        # 2 4 4 (1x2, 2x4)
       
        # n = 11
        # extend:
        # 1 1 1 1 1 1 1 1 1 1 1
        # 1 1 1 1 1 1 1 1 1 2
        # 1 1 1 1 1 1 1 2 2
        # 1 1 1 1 1 1 1 4
        # 1 1 1 1 1 2 2 2
        # 1 1 1 1 1 6
        # 1 1 1 1 1 2 4
        # 1 1 1 2 2 2 2
        # 1 1 1 2 6 
        # 1 1 1 2 2 4
        # 1 1 1 4 4
        # 1 2 2 2 2 2
        # 1 2 2 2 4 
        # 1 2 2 6 (2x2, 0x4)
        # 1 6 4 (0x2, 1x4)
        # 1 2 4 4 (1x2, 2x4)

        # n = 12
        # extend:
        # 1 1 1 1 1 1 1 1 1 1 1 1
        # 1 1 1 1 1 1 1 1 1 1 2
        # 1 1 1 1 1 1 1 1 2 2
        # 1 1 1 1 1 1 1 1 4
        # 1 1 1 1 1 1 2 2 2
        # 1 1 1 1 1 1 6
        # 1 1 1 1 1 1 2 4
        # 1 1 1 1 2 2 2 2
        # 1 1 1 1 2 6 
        # 1 1 1 1 2 2 4
        # 1 1 1 1 4 4
        # 1 1 2 2 2 2 2
        # 1 1 2 2 2 4 
        # 1 1 2 2 6
        # 1 1 6 4
        # 1 1 2 4 4
        # new:
        # 2 2 2 2 2 2
        # 2 2 2 2 4 
        # 2 2 2 6
        # 6 6 (extra, 0x2, 0x4)
        # 2 6 4 (1x2, 1x4)
        # 2 2 4 4 (2x2, 2x4)

        # n = 13
        # extend:
        # 1 1 1 1 1 1 1 1 1 1 1 1 1
        # 1 1 1 1 1 1 1 1 1 1 1 2
        # 1 1 1 1 1 1 1 1 1 2 2
        # 1 1 1 1 1 1 1 1 1 4
        # 1 1 1 1 1 1 1 2 2 2
        # 1 1 1 1 1 1 1 6
        # 1 1 1 1 1 1 1 2 4
        # 1 1 1 1 1 2 2 2 2
        # 1 1 1 1 1 2 6 
        # 1 1 1 1 1 2 2 4
        # 1 1 1 1 1 4 4
        # 1 1 1 2 2 2 2 2
        # 1 1 1 2 2 2 4 
        # 1 1 1 2 2 6
        # 1 1 1 6 4
        # 1 1 1 2 4 4
        # 1 2 2 2 2 2 2
        # 1 2 2 2 2 4 
        # 1 2 2 2 6
        # 1 6 6 (0x2, 0x4)
        # 1 2 6 4 (1x2, 1x4)
        # 1 2 2 4 4 (2x2, 2x4)

        # => f(n) = 1+sum(i//2 if i%2 == 0 else 0 for i in xrange(2, n+1))
        return (1+((n//2)+1)*(n//2)//2)%MOD


# Time:  O(1)
# Space: O(1)
# math
class Solution2(object):
    def numberOfWays(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        def count_1_2_6(n):
            # sum((n-6*i)//2+1 for i in xrange((n//6)+1))
            # = sum(((n//2)+1)-3*i for i in xrange((n//6)+1))
            return (n//2+1)*((n//6)-0+1)-3*((n//6)+0)*((n//6)-0+1)//2

        return reduce(lambda x, y: (x+count_1_2_6(n-4*y))%MOD, (i for i in xrange(min(n//4, 2)+1)), 0)


# Time:  O(n)
# Space: O(1)
# math
class Solution3(object):
    def numberOfWays(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        def count_1_2(n):
            return n//2+1
    
        def count_1_2_6(n):
            return sum(count_1_2(n-6*i) for i in xrange((n//6)+1))

        return reduce(lambda x, y: (x+count_1_2_6(n-4*y))%MOD, (i for i in xrange(min(n//4, 2)+1)), 0)


# Time:  O(n)
# Space: O(n)
# dp
class Solution4(object):
    def numberOfWays(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        dp = [0]*(n+1)
        dp[0] = 1
        for i in (1, 2, 6):
            for j in xrange(i, n+1):
                dp[j] += dp[j-i]
        return reduce(lambda x, y: (x+dp[n-4*y])%MOD, (i for i in xrange(min(n//4, 2)+1)), 0)
