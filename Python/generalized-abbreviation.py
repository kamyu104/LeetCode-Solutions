# Time:  O(n * 2^n)
# Space: O(n)

class Solution(object):
    def generateAbbreviations(self, word):
        """
        :type word: str
        :rtype: List[str]
        """
        def generateAbbreviationsHelper(word, i, cur, res):
            if i == len(word):
                res.append("".join(cur))
                return
            cur.append(word[i])
            generateAbbreviationsHelper(word, i + 1, cur, res)
            cur.pop()
            if not cur or not cur[-1][-1].isdigit():
                for l in xrange(1, len(word) - i + 1):
                    cur.append(str(l))
                    generateAbbreviationsHelper(word, i + l, cur, res)
                    cur.pop()

        res, cur = [], []
        generateAbbreviationsHelper(word, 0, cur, res)
        return res

