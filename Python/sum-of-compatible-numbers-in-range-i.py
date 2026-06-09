# Time:  O(log(n + k))
# Space: O(log(n + k))

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
            cnt = [0]*(l+1)
            cnt[0] = 1
            total = [0]*(l+1)
            for i in xrange(l):
                cnt[i+1] = cnt[i]*2 if not n&(1<<i) else cnt[i]
                total[i+1] = total[i]*2+(1<<i)*cnt[i] if not n&(1<<i) else total[i]
            result = prefix = 0
            for i in reversed(xrange(l)):
                if not x&(1<<i):
                    continue
                result += prefix*cnt[i]+total[i]
                if n&(1<<i):
                    return result
                prefix |= 1<<i
            result += prefix
            return result

        return count(n+k)-count((n-k)-1)


# Time:  O(k)
# Space: O(k)
# simulation
class Solution2(object):
    def sumOfGoodIntegers(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        return sum(i for i in xrange(max(n-k, 1), (n+k)+1) if n&i == 0)
