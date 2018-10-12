# Time:  O(n)
# Space: O(c), c is unique count of pattern

from itertools import izip  # Generator version of zip.

class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        if len(pattern) != self.wordCount(str):
            return False

        w2p, p2w = {}, {}
        for p, w in izip(pattern, self.wordGenerator(str)):
            if w not in w2p and p not in p2w:
                # Build mapping. Space: O(c)
                w2p[w] = p
                p2w[p] = w
            elif w not in w2p or w2p[w] != p:
                # Contradict mapping.
                return False
        return True

    def wordCount(self, str):
        cnt = 1 if str else 0
        for c in str:
            if c == ' ':
                cnt += 1
        return cnt

    # Generate a word at a time without saving all the words.
    def wordGenerator(self, str):
        w = ""
        for c in str:
            if c == ' ':
                yield w
                w = ""
            else:
                w += c
        yield w


# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        words = str.split()  # Space: O(n)
        if len(pattern) != len(words):
            return False

        w2p, p2w = {}, {}
        for p, w in izip(pattern, words):
            if w not in w2p and p not in p2w:
                # Build mapping. Space: O(c)
                w2p[w] = p
                p2w[p] = w
            elif w not in w2p or w2p[w] != p:
                # Contradict mapping.
                return False
        return True

