# Time:  O(n)
# Space: O(26)

# freq table, greedy
class Solution(object):
    def minimumPushes(self, word):
        """
        :type word: str
        :rtype: int
        """
        cnt = collections.Counter(word)
        return sum(x*(i//(9-2+1)+1) for i, x in enumerate(sorted(cnt.itervalues(), reverse=True)))
