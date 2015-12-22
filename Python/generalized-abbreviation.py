# Time:  O(n * 2^n)
# Space: O(n)

class Solution(object):
    def generateAbbreviations(self, word):
        """
        :type word: str
        :rtype: List[str]
        """
        def generateAbbreviationsHelper(word, i, is_prev_num, cur, res):
            if i == len(word):
                res.append("".join(cur))
                return
            cur.append(word[i])
            generateAbbreviationsHelper(word, i + 1, False, cur, res)
            cur.pop()
            if not is_prev_num:
                for l in xrange(1, len(word) - i + 1):
                    cur.append(str(l))
                    generateAbbreviationsHelper(word, i + l, True, cur, res)
                    cur.pop()

        res, cur = [], []
        generateAbbreviationsHelper(word, 0, False, cur, res)
        return res
