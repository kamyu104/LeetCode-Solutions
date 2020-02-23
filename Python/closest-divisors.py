# Time:  O(sqrt(n))
# Space: O(1)

class Solution(object):
    def closestDivisors(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        def divisors(n):
            for d in reversed(xrange(1, int(n**0.5)+1)):
                if n % d == 0:
                    return d, n//d
            return 1, n

        return min([divisors(num+1), divisors(num+2)], key=lambda x: x[1]-x[0])



# Time:  O(sqrt(n))
# Space: O(1)
class Solution2(object):
    def closestDivisors(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        result, d = [1, num+1], 1
        while d*d <= num+2:
            if (num+2) % d == 0:
                result = [d, (num+2)//d]
            if (num+1) % d == 0:
                result = [d, (num+1)//d]
            d += 1
        return result
