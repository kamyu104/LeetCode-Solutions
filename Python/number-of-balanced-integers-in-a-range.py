# Time:  O(d^2)
# Space: O(d^2)

# memoization
class Solution(object):
    def countBalanced(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: int
        """
        def count(n):
            digits = []
            while n:
                n, r = divmod(n, 10)
                digits.append(r)
            digits.reverse()
            memo = [[-1]*(len(digits)*9+1) for _ in xrange(len(digits))]
            def memoization(i, curr, tight):
                if i == len(digits):
                    return curr == 0
                if not tight and memo[i][curr] != -1:
                    return memo[i][curr]
                bound = digits[i] if tight else 9
                result = 0
                for d in xrange(bound+1):
                    result += memoization(i+1, curr-d if (i & 1) else curr+d, tight and d == bound)
                if not tight:
                    memo[i][curr] = result
                return result
            
            return memoization(0, 0, True)
        
        return count(high)-count(low-1)


# Time:  O(d^2)
# Space: O(d^2)
# memoization
class Solution2(object):
    def countBalanced(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: int
        """
        def count(n):
            digits = []
            while n:
                n, r = divmod(n, 10)
                digits.append(r)
            digits.reverse()
            memo = [[[-1]*2 for _ in xrange(len(digits)*9+1)] for _ in xrange(len(digits))]
            def memoization(i, curr, tight):
                if i == len(digits):
                    return int(curr == 0)
                if memo[i][curr][tight] == -1:
                    bound = digits[i] if tight else 9
                    result = 0
                    for d in xrange(bound+1):
                        result += memoization(i+1, curr-d if (i & 1) else curr+d, tight and d == bound)
                    memo[i][curr][tight] = result
                return memo[i][curr][tight]
            
            return memoization(0, 0, True)
        
        return count(high)-count(low-1)


# Time:  O(d^2)
# Space: O(d^2)
# dp
class Solution3(object):
    def countBalanced(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: int
        """
        def count(n):
            digits = []
            while n:
                n, r = divmod(n, 10)
                digits.append(r)
            digits.reverse()
            dp = [[[0]*2 for _ in xrange(len(digits)*9+1)] for _ in xrange(len(digits)+1)]
            dp[0][0][1] = 1
            for i in xrange(len(digits)):
                for curr in xrange(len(dp[i])):
                    curr -= len(digits)//2*9
                    for tight in xrange(2):
                        if not dp[i][curr][tight]:
                            continue
                        bound = digits[i] if tight else 9
                        for d in xrange(bound+1):
                            dp[i+1][curr-d if (i & 1) else curr+d][tight and d == bound] += dp[i][curr][tight]
            return dp[-1][0][0]+dp[-1][0][1]
        
        return count(high)-count(low-1)
