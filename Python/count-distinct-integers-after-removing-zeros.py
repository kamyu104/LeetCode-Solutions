# Time:  O(logn)
# Space: O(1)

# combinatorics
class Solution(object):
    def countDistinct(self, n):
        """
        :type n: int
        :rtype: int
        """
        def reverse(n):
            result, base = 0, 1
            while n:
                n, r = divmod(n, 10)
                result = result*10+r
                base *= 9
            return result, base

        m, base = reverse(n+1)
        result = (base-9)//(9-1)
        base //= 9
        while base:
            m, r = divmod(m, 10)
            if r == 0:
                break
            result += (r-1)*base
            base //= 9
        return result


# Time:  O(logn)
# Space: O(logn)
# combinatorics
class Solution2(object):
    def countDistinct(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = str(n)
        base = pow(9, len(s))
        result = (base-9)//(9-1)
        base //= 9
        for x in s:
            if x == '0':
                break
            result += ((ord(x)-ord('0'))-1)*base
            base //= 9
        if base == 0:
            result += 1
        return result
