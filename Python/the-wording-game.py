# Time:  O(n + m)
# Space: O(1)

# greedy
class Solution(object):
    def canAliceWin(self, a, b):
        """
        :type a: List[str]
        :type b: List[str]
        :rtype: bool
        """
        def is_closely_greater(a, b):
            return ord(a[0])-ord(b[0]) <= 1 and a > b

        result = True
        i, j = 0, -1
        while True:
            j = next((j for j in xrange(j+1, len(b)) if is_closely_greater(b[j], a[i])), len(b))
            while j+1 < len(b) and b[j+1][0] == b[j][0] and is_closely_greater(b[j+1], a[i]):
                j += 1
            if j == len(b):
                break
            a, b, i, j, result = b, a, j, i, not result
        return result
