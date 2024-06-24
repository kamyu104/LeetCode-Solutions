# Time:  O(n * max(cnt)) <= O(n^3)
# Space: O(n + max(cnt)) <= O(n^2)

# dp, combinatorics, sliding window, two pointers
class Solution(object):
    def numberOfPermutations(self, n, requirements):
        """
        :type n: int
        :type requirements: List[List[int]]
        :rtype: int
        """
        MOD = 10**9+7
        lookup = [-1]*n
        for i, c in requirements:
            lookup[i] = c
        max_c = max(lookup)
        dp = [1]
        prev = 0
        for i in xrange(n):
            q = [0]*(i+1)
            dp.extend(0 for _ in xrange(min((i+1)-1, ((max_c+1)-prev)-len(dp))))
            for j in xrange(len(dp)):
                dp_j = dp[j]
                if j-1 >= 0:
                    dp[j] = (dp[j]+dp[j-1])%MOD
                if j-(i+1) >= 0:
                    dp[j] = (dp[j]-q[(j-(i+1))%len(q)])%MOD
                q[j%len(q)] = dp_j
            if lookup[i] != -1:
                dp = [dp[lookup[i]-prev] if lookup[i]-prev < len(dp) else 0]
                prev = lookup[i]
        return dp[-1]


# Time:  O(n * max(cnt)) <= O(n^3)
# Space: O(n + max(cnt)) <= O(n^2)
# dp, combinatorics, sliding window, two pointers
class Solution2(object):
    def numberOfPermutations(self, n, requirements):
        """
        :type n: int
        :type requirements: List[List[int]]
        :rtype: int
        """
        MOD = 10**9+7
        lookup = [-1]*n
        for i, c in requirements:
            lookup[i] = c
        dp = [0]*(max(lookup)+1)
        dp[0] = 1
        for i in xrange(n):
            new_dp = [0]*len(dp)
            if lookup[i] != -1:  # optimized
                new_dp[lookup[i]] = reduce(lambda total, i: (total+dp[i])%MOD, xrange(max(lookup[i]-i, 0), lookup[i]+1), 0)
            else:
                for j in xrange(len(dp)):
                    new_dp[j] = dp[j]
                    if j-1 >= 0:
                        new_dp[j] = (new_dp[j]+new_dp[j-1])%MOD
                    if j-(i+1) >= 0:
                        new_dp[j] = (new_dp[j]-dp[j-(i+1)])%MOD
            dp = new_dp
        return dp[-1]


# Time:  O(n * max(cnt)) <= O(n^3)
# Space: O(n + max(cnt)) <= O(n^2)
# dp, combinatorics, sliding window, two pointers
class Solution3(object):
    def numberOfPermutations(self, n, requirements):
        """
        :type n: int
        :type requirements: List[List[int]]
        :rtype: int
        """
        MOD = 10**9+7
        lookup = [-1]*n
        for i, c in requirements:
            lookup[i] = c
        dp = [0]*(max(lookup)+1)
        dp[0] = 1
        for i in xrange(n):
            new_dp = [0]*len(dp)
            curr = 0
            for j in xrange(len(dp)):
                curr = (curr+dp[j])%MOD
                if j-(i+1) >= 0:
                    curr = (curr-dp[j-(i+1)])%MOD
                new_dp[j] = curr if lookup[i] == -1 or lookup[i] == j else 0
            dp = new_dp
        return dp[-1]
