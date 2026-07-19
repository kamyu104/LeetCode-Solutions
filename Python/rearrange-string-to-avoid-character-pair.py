# Time:  O(n)
# Space: O(1)

# two pointers
class Solution(object):
    def rearrangeString(self, s, x, y):
        """
        :type s: str
        :type x: str
        :type y: str
        :rtype: str
        """
        result = list(s)
        left, right = 0, len(result)-1
        while left < right:
            if result[left] != x:
                left += 1
                continue
            if result[right] != y:
                right -= 1
                continue
            result[left], result[right] = result[right], result[left]
            left += 1
            right -= 1
        return "".join(result)
