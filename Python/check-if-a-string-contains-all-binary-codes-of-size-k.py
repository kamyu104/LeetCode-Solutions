# Time:  O(n * k)
# Space: O(k * 2^k)

class Solution(object):
    def hasAllCodes(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        return 2**k <= len(s) and len({s[i:i+k] for i in xrange(len(s)-k+1)}) == 2**k
    

# Time:  O(n * k)
# Space: O(2^k)
class Solution2(object):
    def hasAllCodes(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        lookup = set()
        base = 2**k
        if base > len(s):
            return False
        num = 0
        for i in xrange(len(s)):
            num = (num << 1) + (s[i] == '1')
            if i >= k-1:
                lookup.add(num)
                num -= (s[i-k+1] == '1') * (base//2)
        return len(lookup) == base
