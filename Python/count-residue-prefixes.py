# Time:  O(n + 26)
# Space: O(26)

# hash table
class Solution(object):
    def residuePrefixes(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = distinct = 0
        lookup = [False]*26
        for i, x in enumerate(s):
            if not lookup[ord(x)-ord('a')]:
                distinct += 1
                if distinct >= 3:
                    break
            lookup[ord(x)-ord('a')] = True
            if distinct == (i+1)%3:
                result += 1
        return result


# Time:  O(n)
# Space: O(3)
# hash table
class Solution2(object):
    def residuePrefixes(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        lookup = set()
        for i, x in enumerate(s):
            lookup.add(x)
            if len(lookup) >= 3:
                break
            if len(lookup) == (i+1)%3:
                result += 1
        return result
