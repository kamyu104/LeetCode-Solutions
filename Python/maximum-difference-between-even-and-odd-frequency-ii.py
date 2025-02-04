# Time:  O(d^2 * n)
# Space: O(n)

# prefix sum, two pointers, sliding window
class Solution(object):
    def maxDifference(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        def diff(x, y):
            prefix1, prefix2, prefix = [0]*(len(s)+1), [0]*(len(s)+1), [0]*(len(s)+1)
            for i in xrange(len(s)):
                prefix1[i+1] = prefix1[i]+int(s[i] == x)
                prefix2[i+1] = prefix2[i]+int(s[i] == y)
                prefix[i+1] = prefix[i]+(int(s[i] == x)-int(s[i] == y))
            result = float("-inf")
            mn = [[float("inf")]*2 for _ in xrange(2)]
            left = 0
            for right in xrange(k-1, len(s)):
                while k <= right-left+1 and prefix1[right+1]-prefix1[left] and prefix2[right+1]-prefix2[left]:
                    i, j = prefix1[left]%2, prefix2[left]%2
                    mn[i][j] = min(mn[i][j], prefix[left])
                    left += 1
                i, j = prefix1[right+1]%2, prefix2[right+1]%2
                result = max(result, prefix[right+1]-mn[i^1][j])
            return result
        
        lookup = set(s)
        return max(diff(x, y) for x in lookup for y in lookup if x != y)
