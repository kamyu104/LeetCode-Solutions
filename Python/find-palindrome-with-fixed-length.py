# Time:  O(n * l)
# Space: O(1)

# math
class Solution(object):
    def kthPalindrome(self, queries, intLength):
        """
        :type queries: List[int]
        :type intLength: int
        :rtype: List[int]
        """
        def reverse(x):
            result = 0
            while x:
                result = result*10+x%10
                x //= 10
            return result

        def f(l, x):
            x = 10**((l-1)//2)+(x-1)
            if x > 10**((l+1)//2)-1:
                return -1
            return x*10**(l//2)+reverse(x//10 if l%2 else x)

        return [f(intLength, x) for x in queries]


# Time:  O(n * l)
# Space: O(l)
# math
class Solution2(object):
    def kthPalindrome(self, queries, intLength):
        """
        :type queries: List[int]
        :type intLength: int
        :rtype: List[int]
        """
        def f(l, x):
            if 10**((l-1)//2)+(x-1) > 10**((l+1)//2)-1:
                return -1
            s = str(10**((l-1)//2)+(x-1))
            return int(s+s[::-1][l%2:])

        return [f(intLength, x) for x in queries]
