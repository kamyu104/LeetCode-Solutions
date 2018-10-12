# Time:  O(n)
# Space: O(1)

class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        def reverse(s, begin, end):
            for i in xrange((end - begin) // 2):
                s[begin + i], s[end - 1 - i] = s[end - 1 - i], s[begin + i]

        s, i = list(s), 0
        for j in xrange(len(s) + 1):
            if j == len(s) or s[j] == ' ':
                reverse(s, i, j)
                i = j + 1
        return "".join(s)


class Solution2(object):
    def reverseWords(self, s):
        reversed_words = [word[::-1] for word in s.split(' ')]
        return ' '.join(reversed_words)

