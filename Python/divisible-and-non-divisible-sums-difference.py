# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def differenceOfSums(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        return (n+1)*n//2 - 2*(((n//m+1)*(n//m)//2)*m)
