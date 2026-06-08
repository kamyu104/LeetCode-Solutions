# Time:  O(n + rlogr)
# Space: O(r)

# number theory, mobius function, principle of inclusion-exclusion
class Solution(object):
    def maxScore(self, nums, maxVal):
        """
        :type nums: List[int]
        :type maxVal: int
        :rtype: int
        """
        def linear_sieve_of_eratosthenes(n):  # Time: O(n), Space: O(n)
            primes = []
            spf = [-1]*(n+1)  # the smallest prime factor
            for i in xrange(2, n+1):
                if spf[i] == -1:
                    spf[i] = i
                    primes.append(i)
                for p in primes:
                    if i*p > n or p > spf[i]:
                        break
                    spf[i*p] = p
            return spf

        # https://www.geeksforgeeks.org/program-for-mobius-function-set-2/
        def mobius(spf):  # Time: O(n), Space: O(n)
            mu = [0]*len(spf)
            for i in xrange(1, len(mu)):
                mu[i] = 1 if i == 1 else 0 if spf[i//spf[i]] == spf[i] else -mu[i//spf[i]]
            return mu

        mx = max(max(nums), maxVal)
        spf = linear_sieve_of_eratosthenes(mx)
        mu = mobius(spf)
        cnt = [0]*(mx+1)
        for x in nums:
            cnt[x] += 1
        multiple_cnt = [0]*(mx+1)
        for i in xrange(1, mx+1):
            for j in xrange(i, mx+1, i):
                multiple_cnt[i] += cnt[j]
        coprime_cnt = [0]*(mx+1)
        for i in xrange(1, mx+1):
            if not mu[i]*multiple_cnt[i]:
                continue
            for j in xrange(i, mx+1, i):
                coprime_cnt[j] += mu[i]*multiple_cnt[i]
        result = 0
        for i in xrange(1, mx+1):
            c = len(nums)-coprime_cnt[i]
            if cnt[i]:
                result = max(result, i-(c-1 if i != 1 else 0))
            elif i <= maxVal:
                result = max(result, i-max(c, 1))
        return result
