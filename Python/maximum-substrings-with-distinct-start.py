# Time:  O(n + 26)
# Space: O(26)

# hash table
class Solution(object):
    def maxDistinct(self, s):
        """
        :type s: str
        :rtype: int
        """
        return len(set(s))


# Time:  O(n + 26)
# Space: O(26)
# hash table
class Solution2(object):
    def maxDistinct(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        lookup = [False]*26
        for x in s:
            if lookup[ord(x)-ord('a')]:
                continue
            lookup[ord(x)-ord('a')] = True
            result += 1
        return result
