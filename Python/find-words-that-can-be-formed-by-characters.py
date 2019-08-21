# Time:  O(m * n), m is the length of chars, n is the number of words
# Space: O(1)

import collections


class Solution(object):
    def countCharacters(self, words, chars):
        """
        :type words: List[str]
        :type chars: str
        :rtype: int
        """
        def check(s, count2):
            if len(s) > len(chars):
                return False
            count1 = collections.Counter()
            for c in s:
                count1[c] += 1
                if c not in count2 or count2[c] < count1[c]:
                    return False
            return True
        
        count = collections.Counter(chars)
        return sum(len(word) for word in words if check(word, count))

