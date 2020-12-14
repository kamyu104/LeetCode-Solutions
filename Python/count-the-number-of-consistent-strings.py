# Time:  O(n)
# Space: O(1)

class Solution(object):
    def countConsistentStrings(self, allowed, words):
        """
        :type allowed: str
        :type words: List[str]
        :rtype: int
        """
        lookup = [False]*26
        for c in allowed:
            lookup[ord(c)-ord('a')] = True
        result = len(words)
        for word in words:
            for c in word:
                if not lookup[ord(c)-ord('a')]:
                    result -= 1
                    break
        return result
