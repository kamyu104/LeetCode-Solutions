# Time:  O(nlogn + n * f)
# Space: O(n * f)

import bisect


class Solution(object):
    def countRoutes(self, locations, start, finish, fuel):
        """
        :type locations: List[int]
        :type start: int
        :type finish: int
        :type fuel: int
        :rtype: int
        """
        MOD = 10**9+7

        s, f = locations[start], locations[finish];
        locations.sort()
        start, finish = bisect.bisect_left(locations, s), bisect.bisect_left(locations, f)

        left = [[0]*(fuel+1) for _ in xrange(len(locations))]  # left[i][f], last move is toward left to location i by f fuel
        right = [[0]*(fuel+1) for _ in xrange(len(locations))]  # right[i][f], last move is toward right to location i by f fuel
        for f in xrange(1, fuel+1):
            for j in xrange(len(locations)-1):
                d = locations[j+1]-locations[j]
                if f > d:
                    # left[j][f] = right[j+1][f-d(j, j+1)] + 2*right[j+2][f-d(j, j+2)] + ... + 2^(k-1)*right[j+k][f-d(j, j+k)]
                    # => left[j+1][f] = (ight[j+2][f-d(j+1, j+2)] + 2*right[j+3][f-d(j+1, j+3)] + ... + 2^(k-2)*right[j+1+k-1][f-d(j+1, j+1+k-1)]
                    # => left[j+1][f-d(j, j+1)] = right[j+2][f-d(j, j+2)] + 2*right[j+3][f-d(j, j+3)] + ... + 2^(k-2)*right[j+k][f-d(j, j+k)]
                    # => left[j][f] = right[j+1][f-d(j, j+1)] + 2*left[j+1][f-d(j, j+1)]
                    left[j][f] = (right[j+1][f-d] + 2*left[j+1][f-d] % MOD) % MOD;
                elif f == d:
                    left[j][f] = int(j+1 == start)
            for j in xrange(1, len(locations)):
                d = locations[j]-locations[j-1]
                if f > d:
                    # right[j][f] = left[j-1][f-d(j, j-1)] + 2*left[j-2][f-d(j, j-2)] + ... + 2^(k-1)*left[j-k][f-d(j, j-k)]
                    # => right[j-1][f] = left[j-2][f-d(j-1, j-2)] + 2*left[j-3][f-d(j-1, j-3)] + ... + 2^(k-2)*left[j-1-k+1][f-d(j-1, j-1-k+1)]
                    # => right[j-1][f-d(j, j-1)] = left[j-2][f-d(j, j-2)] + 2*left[j-3][f-d(j, j-3)] + ... + 2^(k-2)*left[j-k][f-d(j, j-k)]
                    # => right[j][f] = left[j-1][f-d(j, j-1)] + 2*right[j-1][f-d(j, j-1)]
                    right[j][f] = (left[j-1][f-d] + 2*right[j-1][f-d] % MOD) % MOD
                elif f == d:
                    right[j][f] = int(j-1 == start)
        result = int(start == finish)
        for f in xrange(1, fuel+1):
            result = ((result + left[finish][f]) % MOD + right[finish][f]) % MOD
        return result


# Time:  O(n^2 * f)
# Space: O(n * f)
class Solution2(object):
    def countRoutes(self, locations, start, finish, fuel):
        """
        :type locations: List[int]
        :type start: int
        :type finish: int
        :type fuel: int
        :rtype: int
        """
        MOD = 10**9+7
        dp = [[0]*(fuel+1) for _ in xrange(len(locations))]
        dp[start][0] = 1
        for f in xrange(fuel+1):
            for i in xrange(len(locations)):
                for j in xrange(len(locations)):
                    if i == j:
                        continue
                    d = abs(locations[i]-locations[j])
                    if f-d < 0:
                        continue
                    dp[i][f] = (dp[i][f]+dp[j][f-d])%MOD
        return reduce(lambda x, y: (x+y)%MOD, dp[finish])
