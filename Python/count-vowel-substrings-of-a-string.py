# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def countVowelSubstrings(self, word):
        """
        :type word: str
        :rtype: int
        """
        VOWELS = set("aeiou")
        cnt = collections.Counter()
        result = j = k = 0
        for i, c in enumerate(word):
            if c not in VOWELS:
                cnt = collections.Counter()
                j = k = i+1
                continue
            cnt[c] += 1
            while len(cnt) == 5:
                cnt[word[k]] -= 1
                if cnt[word[k]] == 0:
                    del cnt[word[k]]
                k += 1
            result += k-j
        return result
