# Time:  O(r + n * c)
# Space: O(n)

class Solution(object):
    def wordsTyping(self, sentence, rows, cols):
        """
        :type sentence: List[str]
        :type rows: int
        :type cols: int
        :rtype: int
        """
        def words_fit(sentence, start, cols):
            if len(sentence[start]) > cols:
                return 0

            s, count = len(sentence[start]), 1
            i = (start + 1) % len(sentence)
            while s + 1 + len(sentence[i]) <= cols:
                s += 1 + len(sentence[i])
                count += 1
                i = (i + 1) % len(sentence)
            return count

        wc = [0] * len(sentence)
        for i in xrange(len(sentence)):
            wc[i] = words_fit(sentence, i, cols)

        words, start = 0, 0
        for i in xrange(rows):
            words += wc[start]
            start = (start + wc[start]) % len(sentence)
        return words / len(sentence)

