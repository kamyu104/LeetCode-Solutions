# Time:  O((m + n)logn), m is the number of queries, n is the number of words
# Space: O(n)

import bisect


class Solution(object):
    def numSmallerByFrequency(self, queries, words):
        """
        :type queries: List[str]
        :type words: List[str]
        :rtype: List[int]
        """
        words_freq = sorted(word.count(min(word)) for word in words)
        return [len(words)-bisect.bisect_right(words_freq, query.count(min(query))) \
                for query in queries]
