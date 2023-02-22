# Time:  O(logn)
# Space: O(1)

# greedy, trick
# reference: https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/solutions/3203994/java-c-python-1-line-solution/
class Solution(object):
    def minOperations(self, n):
        """
        :type n: int
        :rtype: int
        """
        def popcount(x):
            return bin(x)[2:].count('1')

        return popcount(n^(n*0b11))


# Time:  O(logn)
# Space: O(1)
# greedy
class Solution2(object):
    def minOperations(self, n):
        """
        :type n: int
        :rtype: int
        """
        result = 0
        while n:
            if n&1:
                n >>= 1
                n += n&1
                result += 1
            n >>= 1
        return result
