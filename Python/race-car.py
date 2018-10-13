# Time : O(nlogn), n is the value of the target
# Space: O(n)


class Solution(object):
    def racecar(self, target):
        dp = [0] * (target+1)
        for i in xrange(1, target+1):
            # 2^(k-1) <= i < 2^k
            k = i.bit_length()

            # case 1. drive exactly i at best
            #         seq(i) = A^k
            if i == 2**k-1:
                dp[i] = k
                continue

            # case 2. drive cross i at 2^k-1, and turn back to i
            #         seq(i) = A^k -> R -> seq(2^k-1 - i)
            dp[i] = k+1 + dp[2**k-1 - i]

            # case 3. drive less then 2^k-1, and turn back some distance,
            #         and turn back again to make the direction is the same
            #         seq(i) = shortest(seq(i), A^(k-1) -> R -> A^j -> R ->
            #                                   seq(i - (2^(k-1)-1) + (2^j-1)),
            #                  where 0 <= j < k-1)
            #         => dp[i] = min(dp[i], (k-1) + 1 + j + 1 +
            #                               dp[i - (2**(k-1)-1) + (2**j-1)])
            for j in xrange(k-1):
                dp[i] = min(dp[i], k+j+1 + dp[i - 2**(k-1) + 2**j])

        return dp[-1]

