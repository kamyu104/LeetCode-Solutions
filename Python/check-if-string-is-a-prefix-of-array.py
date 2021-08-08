# Time:  O(n)
# Space: O(1)

class Solution(object):
    def isPrefixString(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: bool
        """
        i = j = 0
        for c in s:
            if i == len(words) or words[i][j] != c:
                return False 
            j += 1
            if j == len(words[i]):
                i += 1
                j = 0
        return j == 0


# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def isPrefixString(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: bool
        """
        i = 0
        for word in words:
            for c in word:
                if i == len(s) or s[i] != c:
                    return False
                i += 1
            if i == len(s):
                return True
        return False
