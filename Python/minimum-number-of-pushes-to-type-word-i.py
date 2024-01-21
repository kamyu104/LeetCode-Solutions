# Time:  O(4)
# Space: O(1)

# greedy
class Solution(object):
    def minimumPushes(self, word):
        """
        :type word: str
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b

        return sum((i+1)*min(len(word)-i*(9-2+1), (9-2+1)) for i in xrange(ceil_divide(len(word), (9-2+1))))


# Time:  O(26)
# Space: O(26)
import collections


# freq table, greedy
class Solution2(object):
    def minimumPushes(self, word):
        """
        :type word: str
        :rtype: int
        """
        return sum(x*(i//(9-2+1)+1) for i, x in enumerate(sorted(collections.Counter(word).itervalues(), reverse=True)))
