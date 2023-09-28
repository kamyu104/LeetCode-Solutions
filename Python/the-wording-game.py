# Time:  O((m + n) * l), l is the max length of word in a and b
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
        for _ in xrange(26*2):  # at most 1(begin)+26*2+1(end) turns by best strategy
            j = next((j for j in xrange(j+1, len(b)) if is_closely_greater(b[j], a[i])), len(b))
            if j == len(b):
                break
            while j+1 < len(b) and b[j+1][0] == b[j][0]:
                j += 1
            a, b, i, j, result = b, a, j, i, not result
        return result
