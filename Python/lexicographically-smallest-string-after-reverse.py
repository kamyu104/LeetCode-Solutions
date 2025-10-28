# Time:  O(n^2)
# Space: O(n)

# brute force
class Solution(object):
    def lexSmallest(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = s
        for k in xrange(2, len(s)+1):
            result = min(result, s[:k][::-1]+s[k:], s[:-k]+s[-k:][::-1])
        return result


# Time:  O(n^2)
# Space: O(n)
# brute force
class Solution2(object):
    def lexSmallest(self, s):
        """
        :type s: str
        :rtype: str
        """
        return min(min(s[:k][::-1]+s[k:], s[:-k]+s[-k:][::-1]) for k in xrange(1, len(s)+1))
