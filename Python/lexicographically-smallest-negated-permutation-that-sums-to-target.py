# Time:  O(n)
# Space: O(1)

# greedy, two pointers
class Solution(object):
    def lexSmallestNegatedPerm(self, n, target):
        """
        :type n: int
        :type target: int
        :rtype: List[int]
        """
        def count(x):
            return (x+1)*x//2

        total = count(n)
        if abs(target) > total or (target-total)%2:
            return []
        result = [0]*n
        left, right = 0, n-1
        for i in reversed(xrange(1, n+1)):
            if target-(-i) <= count(i-1):
                target -= -i
                result[left] = -i
                left += 1
            else:
                target -= i
                result[right] = i
                right -= 1
        return result
    
