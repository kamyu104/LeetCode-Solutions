# Time:  O(nlogn)
# Space: O(1)

# brute force
class Solution(object):
    def sumOfNumberAndReverse(self, num):
        """
        :type num: int
        :rtype: bool
        """
        def reverse(n):
            result = 0
            while n:
                result = result*10 + n%10
                n //= 10            
            return result

        return any(x+reverse(x) == num for x in xrange(num//2, num+1))


# Time:  O(nlogn)
# Space: O(logn)
# brute force
class Solution2(object):
    def sumOfNumberAndReverse(self, num):
        """
        :type num: int
        :rtype: bool
        """
        return any(x+int(str(x)[::-1]) == num for x in xrange(num//2, num+1))
