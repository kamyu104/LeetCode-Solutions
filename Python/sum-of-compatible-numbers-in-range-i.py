# Time:  O(log(n + k))
# Space: O(1)

# combinatorics
class Solution(object):
    def sumOfGoodIntegers(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        def count(x):
            if x <= 0:
                return 0
            l = x.bit_length()
            total, cnt = 0, 1
            for i in xrange(l):
                if n&(1<<i):
                    continue
                total = total*2+(1<<i)*cnt
                cnt *= 2
            result = prefix = 0
            for i in reversed(xrange(l)):
                if not n&(1<<i):
                    cnt //= 2
                    total = (total-(1<<i)*cnt)//2
                if not x&(1<<i):
                    continue
                result += prefix*cnt+total
                if n&(1<<i):
                    return result
                prefix |= 1<<i
            result += prefix
            return result

        return count(n+k)-count((n-k)-1)


# Time:  O(k)
# Space: O(1)
# simulation
class Solution2(object):
    def sumOfGoodIntegers(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        return sum(i for i in xrange(max(n-k, 1), (n+k)+1) if n&i == 0)
