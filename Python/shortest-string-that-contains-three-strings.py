# Time:  O(l^2)
# Space: O(l)

# brute force
class Solution(object):
    def minimumString(self, a, b, c):
        """
        :type a: str
        :type b: str
        :type c: str
        :rtype: str
        """
        def merge(a, b):
            if a in b:
                return b
            l = next((l for l in reversed(xrange(1, min(len(a), len(b)))) if a[-l:] == b[:l]), 0)
            return a+b[l:]

        result = [merge(a, merge(b, c)), merge(a, merge(c, b)),
                  merge(b, merge(a, c)), merge(b, merge(c, a)),
                  merge(c, merge(a, b)), merge(c, merge(b, a))]
        return min(result, key=lambda x: (len(x), x))
