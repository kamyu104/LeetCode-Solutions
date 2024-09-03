# Time:  O(n + 10 * 10^((n + 1)/2))
# Space: O(n + 10 * (10 * nHr(10, n/2)))

# combinatorics, freq table
class Solution(object):
    def countGoodIntegers(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        def reverse(x, n):
            if n%2:
                x //= 10
            result = 0
            while x:
                result = result*10+x%10
                x //= 10
            return result

        def palindrome(x, n):
            return x*(10**(n//2))+reverse(x, n)

        def count(x):
            cnt = [0]*10
            while x:
                cnt[x%10] += 1
                x //= 10
            return tuple(cnt)

        fact = [1]*(n+1)
        for i in xrange(len(fact)-1):
            fact[i+1] = fact[i]*(i+1)
        l = (n+1)//2
        result = 0
        lookup = set()
        for d in xrange(10**(l-1), 10**l):
            x = palindrome(d, n)
            if x%k:
                continue
            cnt = count(x)
            if cnt in lookup:
                continue
            lookup.add(cnt)
            total = (n-cnt[0])*fact[n-1]
            for c in cnt:
                total //= fact[c]
            result += total
        return result
