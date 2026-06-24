# Time:  O(10 * logr)
# Space: O(10)

# dp, prefix sum
class Solution(object):
    def goodIntegers(self, l, r, k):
        """
        :type l: int
        :type r: int
        :type k: int
        :rtype: int
        """
        def count(n):
            if n < 0:
                return 0
            digits = map(int, str(n))
            result = 1
            bound = next((i for i in xrange(1, len(digits)) if abs(digits[i]-digits[i-1]) > k), len(digits))
            if bound == len(digits):
                result += 1
            for i in reversed(xrange(len(digits))):
                dp = [prefix[min(d+k, 9)+1]-prefix[max(d-k, 0)] for d in xrange(10)] if i != len(digits)-1 else [1]*10
                prefix = [0]*(len(dp)+1)
                for j in xrange(len(dp)):
                    prefix[j+1] = prefix[j]+dp[j]
                result += prefix[(digits[0]-1 if i == 0 else 9)+1]-prefix[1]
                if 1 <= i <= bound:
                    result += max(prefix[min(digits[i-1]+k, digits[i]-1)+1]-prefix[max(digits[i-1]-k, 0)], 0)
            return result

        return count(r)-count(l-1)
