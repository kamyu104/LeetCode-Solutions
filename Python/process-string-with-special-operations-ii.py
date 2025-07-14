# Time:  O(n)
# Space: O(1)

# backward simulation
class Solution(object):
    def processStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        l = 0
        for x in s:
            if x == '*':
                l = max(l-1, 0)
            elif x == '#':
                l <<= 1
            elif x == '%':
                continue
            else:
                l += 1
        if k >= l:
            return '.'
        for x in reversed(s):
            if x == '*':
                l += 1
            elif x == '#':
                l >>= 1
                if k >= l:
                    k -= l
            elif x == '%':
                k = (l-1)-k
            else:
                l -= 1
                if l == k:
                    return x
