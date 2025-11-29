# Time:  O(logn * 11 * 11 * 2 * 2 * 10)
# Space: O(logn * 11 * 11 * 2 * 2)

# memoization by dict
class Solution(object):
    def totalWaviness(self, num1, num2):
        """
        :type num1: int
        :type num2: int
        :rtype: int
        """
        def count(x):
            def dp(i, prev, prev2, zero, tight):
                if i == len(s):
                    return 1, 0
                key = (i, prev, prev2, zero, tight)
                if key not in lookup:
                    cnt = w = 0
                    mx = int(s[i]) if tight else 9
                    for d in xrange(mx+1):
                        new_tight = tight and (d == int(s[i]))
                        new_zero = zero and (d == 0)
                        new_prev2 = prev
                        new_prev = d if not new_zero else -1
                        new_cnt, nw = dp(i+1, new_prev, new_prev2, new_zero, new_tight)
                        cnt += new_cnt
                        if not zero and prev2 != -1 and (prev2 < prev and prev > d or prev2 > prev and prev < d):
                            w += new_cnt
                        w += nw
                    lookup[key] = (cnt, w)
                return lookup[key]

            s = str(x)
            lookup = {}
            return dp(0, -1, -1, True, True)[1]

        return count(num2)-count(num1-1)


# Time:  O(logn * 11 * 11 * 2 * 2 * 10)
# Space: O(logn * 11 * 11 * 2 * 2)
# memoization by list
class Solution2(object):
    def totalWaviness(self, num1, num2):
        """
        :type num1: int
        :type num2: int
        :rtype: int
        """
        def count(x):
            def encode(i, prev, prev2, zero, tight):
                key = i
                key = key*(10+1)+(prev+1)
                key = key*(10+1)+(prev2+1)
                key = key*2+(1 if zero else 0)
                key = key*2+(1 if tight else 0)
                return key

            def dp(i, prev, prev2, zero, tight):
                if i == len(s):
                    return 1, 0
                key = encode(i, prev, prev2, zero, tight)
                if lookup[key] is None:
                    cnt = w = 0
                    mx = int(s[i]) if tight else 9
                    for d in xrange(mx+1):
                        new_tight = tight and (d == int(s[i]))
                        new_zero = zero and (d == 0)
                        new_prev2 = prev
                        new_prev = d if not new_zero else -1
                        new_cnt, nw = dp(i+1, new_prev, new_prev2, new_zero, new_tight)
                        cnt += new_cnt
                        if not zero and prev2 != -1:
                            if (prev2 < prev and prev > d) or (prev2 > prev and prev < d):
                                w += new_cnt
                        w += nw
                    lookup[key] = (cnt, w)
                return lookup[key]

            s = str(x)
            lookup = [None]*(len(s)*(10+1)*(10+1)*2*2)
            return dp(0, -1, -1, True, True)[1]

        return count(num2)-count(num1-1)


# Time:  O(logn * 11 * 11 * 2 * 2 * 10)
# Space: O(11 * 11 * 2 * 2)
# dp by dict
class Solution3(object):
    def totalWaviness(self, num1, num2):
        """
        :type num1: int
        :type num2: int
        :rtype: int
        """
        def count(x):
            s = str(x)
            dp = {}
            for prev in xrange(-1, 10):
                for prev2 in xrange(-1, 10):
                    for zero in xrange(2):
                        for tight in xrange(2):
                            dp[(prev, prev2, zero, tight)] = (1, 0)
            for i in reversed(xrange(len(s))):
                new_dp = {}
                for prev in xrange(-1, 10):
                    for prev2 in xrange(-1, 10):
                        for zero in xrange(2):
                            for tight in xrange(2):
                                cnt = w = 0
                                mx = int(s[i]) if tight else 9
                                for d in xrange(mx+1):
                                    new_tight = tight and (d == int(s[i]))
                                    new_zero = zero and (d == 0)
                                    new_prev2 = prev
                                    new_prev = d if not new_zero else -1
                                    key = (new_prev, new_prev2, new_zero, new_tight)
                                    if key in dp:
                                        new_cnt, nw = dp[key]
                                        cnt += new_cnt
                                        if not zero and prev2 != -1 and ((prev2 < prev and prev > d) or (prev2 > prev and prev < d)):
                                            w += new_cnt
                                        w += nw
                                new_dp[(prev, prev2, zero, tight)] = (cnt, w)
                dp = new_dp
            return dp[(-1, -1, True, True)][1]

        return count(num2)-count(num1-1)


# Time:  O(logn * 11 * 11 * 2 * 2 * 10)
# Space: O(11 * 11 * 2 * 2)
# dp by list
class Solution4(object):
    def totalWaviness(self, num1, num2):
        """
        :type num1: int
        :type num2: int
        :rtype: int
        """
        def count(x):
            def encode(prev, prev2, zero, tight):
                key = prev+1
                key = key*(10+1)+(prev2+1)
                key = key*2+(1 if zero else 0)
                key = key*2+(1 if tight else 0)
                return key

            s = str(x)
            state_size = (10+1)*(10+1)*2*2
            dp = [None]*state_size
            for prev in xrange(-1, 10):
                for prev2 in xrange(-1, 10):
                    for zero in xrange(2):
                        for tight in xrange(2):
                            key = encode(prev, prev2, zero, tight)
                            dp[key] = (1, 0)
            for i in reversed(xrange(len(s))):
                new_dp = [None]*state_size
                for prev in xrange(-1, 10):
                    for prev2 in xrange(-1, 10):
                        for zero in xrange(2):
                            for tight in xrange(2):
                                cnt = w = 0
                                mx = int(s[i]) if tight else 9
                                for d in xrange(mx+1):
                                    new_tight = tight and (d == int(s[i]))
                                    new_zero = zero and (d == 0)
                                    new_prev2 = prev
                                    new_prev = d if not new_zero else -1
                                    key = encode(new_prev, new_prev2, new_zero, new_tight)
                                    if dp[key] is not None:
                                        new_cnt, nw = dp[key]
                                        cnt += new_cnt
                                        if not zero and prev2 != -1 and ((prev2 < prev and prev > d) or (prev2 > prev and prev < d)):
                                            w += new_cnt
                                        w += nw
                                new_dp[encode(prev, prev2, zero, tight)] = (cnt, w)
                dp, new_dp = new_dp, dp
            return dp[encode(-1, -1, True, True)][1]

        return count(num2)-count(num1-1)
