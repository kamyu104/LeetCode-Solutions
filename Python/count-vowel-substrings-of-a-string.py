# Time:  O(n)
# Space: O(1)

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


# Time:  O(n)
# Space: O(1)
import collections


class Solution2(object):
    def countVowelSubstrings(self, word):
        """
        :type word: str
        :rtype: int
        """
        VOWELS = set("aeiou")
        k = 5
        def atMost(word, k):
            cnt = collections.Counter()
            result, left, count = 0, 0, 0
            for right in xrange(len(word)):
                if word[right] not in VOWELS:
                    cnt = collections.Counter()
                    left = right+1
                    continue
                cnt[word[right]] += 1
                while len(cnt) > k:
                    cnt[word[left]] -=1
                    if not cnt[word[left]]:
                        del cnt[word[left]]
                    left += 1
                result += right-left+1
            return result

        return atMost(word, k) - atMost(word, k-1)
