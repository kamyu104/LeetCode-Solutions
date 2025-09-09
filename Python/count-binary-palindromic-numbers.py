# Time:  O(logn)
# Space: O(1)

# bitmasks, combinatorics
class Solution(object):
    def countBinaryPalindromes(self, n):
        """
        :type n: int
        :rtype: int
        """
        def length(n):
            result = 0
            while n:
                result += 1
                n >>= 1
            return result

        def reverse(n, l):
            result = 0
            for i in xrange(l):
                if n&(1<<i):
                    result |= 1<<((l-1)-i)
            return result
    
        l = length(n)//2
        return ((1<<l)-1)+(n>>l)+int(((n>>l)<<l)|reverse(n>>(length(n)-l), l) <= n)


# Time:  O(logn)
# Space: O(logn)
# bitmasks, combinatorics
class Solution2(object):
    def countBinaryPalindromes(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = map(int, bin(n)[2:])
        l = len(s)//2
        return ((1<<l)-1)+(n>>l)+int(s[:len(s)-l]+s[:l][::-1] <= s)
