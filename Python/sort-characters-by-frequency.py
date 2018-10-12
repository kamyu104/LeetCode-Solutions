# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        freq = collections.defaultdict(int)
        for c in s:
            freq[c] += 1

        counts = [""] * (len(s)+1)
        for c in freq:
            counts[freq[c]] += c

        result = ""
        for count in reversed(xrange(len(counts)-1)):
            for c in counts[count]:
                result += c * count

        return result

