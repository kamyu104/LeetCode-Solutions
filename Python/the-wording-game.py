# Time:  O(m + n), m = sum(len(w) for w in a), n = sum(len(w) for w in b)
# Space: O(1)

# game, greedy
class Solution(object):
    def canAliceWin(self, a, b):
        """
        :type a: List[str]
        :type b: List[str]
        :rtype: bool
        """
        def is_closely_greater(a, b):
            return ord(a[0])-ord(b[0]) <= 1 and a > b

        result = True
        i, j = 0, -1
        for _ in xrange(len({w[0] for w in a})+len({w[0] for w in b})):  # each player takes turns using a word with a different first letter than the last word he played
            j = next((j for j in xrange(j+1, len(b)) if is_closely_greater(b[j], a[i])), len(b))
            if j == len(b):
                break
            while j+1 < len(b) and b[j+1][0] == b[j][0]:  # play the lexicographically greatest word with the same first letter
                j += 1
            a, b, i, j, result = b, a, j, i, not result
        return result
