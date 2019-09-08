# Time:  O(l * rlogr)  , l is the max length of phrases
#                      , r is the number of result, could be up to O(n^2)
# Space: O(l * (n + r)), n is the number of phrases

import collections


class Solution(object):
    def beforeAndAfterPuzzles(self, phrases):
        """
        :type phrases: List[str]
        :rtype: List[str]
        """
        lookup = collections.defaultdict(list)
        for i, phrase in enumerate(phrases):
            right = phrase.rfind(' ')
            word = phrase if right == -1 else phrase[right+1:]
            lookup[word].append(i)

        result_set = set()
        for i, phrase in enumerate(phrases):
            left = phrase.find(' ')
            word = phrase if left == -1 else phrase[:left]
            if word not in lookup:
                continue
            for j in lookup[word]:
                if j == i:
                    continue
                result_set.add(phrases[j] + phrase[len(word):])
        return sorted(result_set)
