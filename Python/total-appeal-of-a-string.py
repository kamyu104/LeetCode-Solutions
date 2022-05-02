# Time:  O(n)
# Space: O(26)

# combinatorics
class Solution(object):
    def appealSum(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = curr = 0
        lookup = [-1]*26
        for i, c in enumerate(s):
            result += (i-lookup[ord(c)-ord('a')])*(len(s)-i)
            lookup[ord(c)-ord('a')] = i
        return result


# Time:  O(n)
# Space: O(26)
# counting
class Solution2(object):
    def appealSum(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = cnt = 0
        lookup = [-1]*26
        for i, c in enumerate(s):
            cnt += i-lookup[ord(c)-ord('a')]
            lookup[ord(c)-ord('a')] = i
            result += cnt
        return result

