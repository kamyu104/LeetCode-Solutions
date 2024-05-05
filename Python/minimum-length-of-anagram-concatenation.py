# Time:  O(sqrt(n) * n + (26 * sum(n/i for i in range(1, n+1) if n%i == 0))) < O(sqrt(n) * n + 26 * sum(n/i for i in range(1, n+1)) = O(sqrt(n) * n + 26 * nlogn)
# Space: O(26)

# number theory, freq table
class Solution(object):
    def minAnagramLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        def factors(n):
            for i in xrange(1, n+1):
                if i*i > n:
                    break
                if n%i:
                    continue
                yield i
                if n//i != i:
                    yield n//i
                    
        def check(l):
            def count(i):
                cnt = [0]*26
                for j in xrange(i, i+l):
                    cnt[ord(s[j])-ord('a')] += 1
                return cnt
    
            cnt = count(0)
            return all(count(i) == cnt for i in xrange(l, len(s), l))

        return min(l for l in factors(len(s)) if check(l))
